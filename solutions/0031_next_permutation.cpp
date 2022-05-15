#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size() == 1) return;
        int n = nums.size();
        int i = n - 2;
        for (; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) break;
        }
        if (i == -1) {
            reverse(nums.begin(), nums.end());
        } else {
            int j = n - 1;
            for (; j > i; j--) {
                if (nums[j] > nums[i]) break;
            }
            swap(nums[i], nums[j]);
            reverse(nums.begin() + i + 1, nums.end());
        }
    }
};