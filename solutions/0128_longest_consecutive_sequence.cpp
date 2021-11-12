#include <unordered_set>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int max = 0;
        unordered_set<int> us(nums.begin(), nums.end()); // not accessed
        for (int num : nums) {
            if (!us.count(num)) continue;
            int prev = num, next = num;
            while (us.count(--prev)) us.erase(prev);
            while (us.count(++next)) us.erase(next);
            max = (next - prev - 1 > max)? next - prev - 1 : max;
        }
        return max;
    }
};

int main() {
    vector<int> nums = {100, 4, 200, 1, 3, 2};
    Solution sol;
    cout << sol.longestConsecutive(nums) << endl;
}
