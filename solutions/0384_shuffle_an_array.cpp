#include <vector>
#include <cstdlib>

using namespace std;

class Solution {
public:
    vector<int> nums;
    Solution(vector<int> &nums_) {
        nums = nums_;
    }

    vector<int> reset() {
        return nums;
    }

    vector<int> shuffle() {
        vector<int> res = nums;
        for (int i = nums.size() - 1; i > 0 ; i--) {
            int r = rand() % (i + 1);
            swap(res[i], res[r]);
        }
        return res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */