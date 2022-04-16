#include <vector>

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, j = 0;
        while (j < nums.size()) {
            if (nums[j] != 0) {
                nums[i++] = nums[j++];
                continue;
            }
            while (j < nums.size() && nums[j] == 0) j++;
            if (j == nums.size()) break;
            nums[i++] = nums[j++];
        }
        for (int k = i; k < nums.size(); k++) nums[k] = 0;
    }
};