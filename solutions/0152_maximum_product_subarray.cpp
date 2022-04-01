// dp
#include <vector>

using namespace std;

class Solution {
public:
    int max(int a, int b) { return a > b ? a : b; }

    int min(int a, int b) { return a < b ? a : b; }

    int max(int a, int b, int c) { return max(a, max(b, c)); }

    int min(int a, int b, int c) { return min(a, min(b, c)); }

    int maxProduct(vector<int> &nums) {
        int res = nums[0], maxn = nums[0], minn = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int maxn_ = max(nums[i], nums[i] * maxn, nums[i] * minn);
            int minn_ = min(nums[i], nums[i] * maxn, nums[i] * minn);
            if (maxn_ > res) res = maxn_;
            maxn = maxn_;
            minn = minn_;
        }
        return res;
    }
};