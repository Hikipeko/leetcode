#include <vector>

using namespace std;

class Solution {
public:
    // 1, < next, 0, peak, -1 < prev
    int is_peak(const vector<int> &nums, int i) {
        if (i == 0)
            return nums[0] > nums[1] ? 0 : 1;
        if (i == nums.size() - 1)
            return nums[i] > nums[i - 1] ? 0 : -1;
        if (nums[i] < nums[i + 1]) return 1;
        if  (nums[i] < nums[i - 1]) return -1;
        return 0;
    }

    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size();
        if (r == 1) return 0;
        while (l < r) {
            int mid = (l + r) / 2;
            int res = is_peak(nums, mid);
            if (res == 0) return mid;
            else if (res == 1) l = mid;
            else r = mid;
        }
        return -1;
    }
};