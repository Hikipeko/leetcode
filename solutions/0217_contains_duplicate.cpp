#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
#include <numeric>

using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int> &nums) {
        if (nums.size() < 2) return false;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 1; i++)
            if (nums[i] == nums[i + 1]) return true;
        return false;
    }
};