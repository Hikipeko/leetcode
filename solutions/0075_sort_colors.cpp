#include <vector>

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int cnt[3] = {0, 0, 0};
        for (auto n : nums)
            cnt[n]++;
        for (int i = 0; i < nums.size(); i++) {
            if (i < cnt[0]) nums[i] = 0;
            else if (i < cnt[0] + cnt[1]) nums[i] = 1;
            else nums[i] = 2;
        }
    }
};