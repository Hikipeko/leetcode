#include <vector>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reach = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (i > reach) return false;
            int r = i + nums[i] ;
            reach = reach > r ? reach : r;
            if (reach >= nums.size() - 1) return true;
        }
        return false;
    }
};
