#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>
#include <numeric>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int> &nums) {
        int sum = 0, n = nums.size() + 1;
        for (int i : nums) sum += i;
        return n * (n + 1) / 2 - sum;
    }
};