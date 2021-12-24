#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() < 2) return nums.size();
        int curr = 0, next = 1;
        while (next < nums.size()) {
            if (nums[curr] == nums[next]) next++;
            else {
                nums[++curr] = nums[next++];
            }
        }
        return curr + 1;
    }
};