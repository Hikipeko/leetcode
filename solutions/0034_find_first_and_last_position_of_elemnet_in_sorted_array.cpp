#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> temp(2,-1);
        if (nums.empty()) return temp;
        int l = 0, n = nums.size(), r = n, m;
        vector<int> res;
        while (l < r) {
            m = (l + r) / 2;
            if (nums[m] >= target) r = m;
            else l = m + 1;
        }
        if (l >= n || nums[l] != target) return temp;
        res.push_back(l);

        l = 0, r = n;
        while (l < r) {
            m = (l + r) / 2;
            if (nums[m] <= target) l = m + 1;
            else r = m;
        }
        l--;
        res.push_back(l);
        return res;
    }
};