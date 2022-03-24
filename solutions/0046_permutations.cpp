#include <string>
#include <vector>

// backtracking
using namespace std;

class Solution {
public:
    int n;
    vector<vector<int>> res;
    vector<int> nums;

    vector<vector<int>> permute(vector<int>& nums_) {
        n = 0;
        nums = nums_;
        return res;
    }

    void help_perm() {
        if (i == n) {
            res.push_back(nums);
            return;
        }
        for (int i = n; i < nums.size(); i++) {
            swap(nums[n], nums[i]);
            n++;
            help_perm();
            n--;
            swap(nums[n], nums[i]);
        }
    }
};