#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> res = vector<vector<int>>();
        if (nums.size() < 3) return res;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) {
            if (nums[i] > 0) break;
            if (i >= 1 && nums[i] == nums[i - 1]) continue;
            int tar = 0 - nums[i], j = i + 1, k = nums.size() - 1;
            while (j < k) {
                if (nums[j] + nums[k] < tar) j++;
                else if (nums[j] + nums[k] > tar) k--;
                else if (res.empty() || res.back()[0] != nums[i] || res.back()[1] != nums[j])
                    res.push_back({nums[i], nums[j++], nums[k--]});
                else {j++; k--;}
            }
        }
        return res;
    }
};