#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size();
        while (l != r) {
            int m = l + (r - l) / 2;
            if (nums[m] < target)
                l = m + 1;
            else if (nums[m] > target)
                r = m;
            else
                return m;
        }
        return r;
    }
};
