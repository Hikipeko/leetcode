#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int> &nums1, vector<int> &nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        vector<int> res;
        auto it1 = nums1.begin(), it2 = nums2.begin();
        while (it1 != nums1.end() && it2 != nums2.end()) {
            if (*it1 < *it2) {
                it1++;
            } else if (*it1 > *it2)
                it2++;
            else {
                if (res.empty() || *it1 != res.back())
                    res.push_back(*it1);
                it1++;
                it2++;
            }
        }
        return res;
    }
};