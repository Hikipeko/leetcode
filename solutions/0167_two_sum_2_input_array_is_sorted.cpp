#include <unordered_map>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (true) {
            if (nums[left] + nums[right] > target)
                right --;
            else if (nums[left] + nums[right] < target)
                left++;
            else break;
        }
        return vector<int> {left + 1, right + 1};
    }
};

int main() {
    Solution sol;
    vector<int> nums = {2,7,11,15};
    vector<int> t =  sol.twoSum(nums, 9) ;
    for (auto it : t) cout << it << endl;
    return 0;
}
