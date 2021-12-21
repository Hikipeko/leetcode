#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        return (findKth(nums1, nums2, 0, 0, (nums1.size() + nums2.size() + 2) / 2)
                + findKth(nums1, nums2, 0, 0, (nums1.size() + nums2.size() + 1) / 2)) / 2;
    }

    int min(int l, int r) { return l < r ? l : r; }

    double findKth(vector<int> &nums1, vector<int> &nums2, int l1, int l2, int k) {
        if (l1 >= nums1.size()) return nums2[l2 + k - 1];
        if (l2 >= nums2.size()) return nums1[l1 + k - 1];
        if (k == 1) return min(nums1[l1], nums2[l2]);
        int m1 = (l1 + k / 2 - 1 < nums1.size()) ? nums1[l1 + k / 2 - 1] : INT_MAX;
        int m2 = (l2 + k / 2 - 1 < nums2.size()) ? nums2[l2 + k / 2 - 1] : INT_MAX;
        if (m1 < m2)
            return findKth(nums1, nums2, l1 + k/2, l2, k - k / 2);
        else
            return findKth(nums1, nums2, l1, l2 + k/2, k - k / 2);
    }
};