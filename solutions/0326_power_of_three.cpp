#include <climits>

class Solution {
public:
    bool isPowerOfThree(int n) {
        int i = 1;
        for (; i <= n && i <= INT_MAX / 3; i *= 3) {}
        return i == n;
    }
};