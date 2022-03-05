#include <vector>

using namespace std;

class Solution {
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        vector<int> res;
        int i = 0, j = 0;
        while (i < m || j < n) {
            if (i == m) res.push_back(nums2[j++]);
            else if (j == n || nums1[i] < nums2[j]) res.push_back(nums1[i++]);
            else res.push_back(nums2[j++]);
        }
        nums1 = res;
    }
};