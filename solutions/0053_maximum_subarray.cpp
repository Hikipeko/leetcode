#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int currSum = nums[0], res = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            if (currSum < 0) currSum = nums[i];
            else currSum += nums[i];
            if (currSum > res) res = currSum;
        }
        return res;
    };
};