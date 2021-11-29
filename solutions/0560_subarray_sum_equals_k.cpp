#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sum = 0, cnt = 0;
        unordered_map<int, int> sums;
        sums[0] = 1;
        for (int i : nums) {
            sum += i;
            cnt += sums[sum - k];
            sums[sum]++;
        }
        return cnt;
    }
};

