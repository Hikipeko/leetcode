#include <unordered_map>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int left = 0, right = 0, sum = 0, res = 0;
        while (right < nums.size()) {
            if (sum < target) {
                sum += nums[right++];
            } else {
                if (res == 0 || right - left < res) res = right - left;
                sum -= nums[left++];
            }
        }
        while (sum >= target) {
            if (res == 0 || right - left < res) res = right - left;
            sum -= nums[left++];
        }
        return res;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2,3,1,2,4,3};
    cout << sol.minSubArrayLen(7, nums) << endl;
    return 0;
}