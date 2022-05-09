#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        auto it = nums.begin() + nums.size() / 2;
        nth_element(nums.begin(), it, nums.end());
        int m = *it;

    }
};
