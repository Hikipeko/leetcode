#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        int l = nums.size();
        for (int i = 0; i < (1 << l); i++) {
            vector<int> s;
            int temp = i;
            for (int j = 0; j < l; j++) {
                if (temp % 2 == 1) s.push_back(nums[j]);
                temp = temp >> 1;
                if (temp == 0) break;
            }
            res.push_back(s);
        }
        return res;
    }
};