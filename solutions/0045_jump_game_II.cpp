#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        int s = 1, curr = 0, next = nums[0];
        if (next >= n - 1) return 1;
        while (true) {
            s++;
            int next_new = 0;
            for (int i = curr + 1; i <= next; i++) {
                if (i + nums[i] > next_new) next_new = i + nums[i];
                if (next_new >= n - 1) return s;
            }
            curr = next;
            next = next_new;
        }
    }
};