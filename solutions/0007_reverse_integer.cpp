#include <climits>

class Solution {
public:
    int abs(int x) {return x > 0 ? x : -x;}

    int reverse(int x) {
        int res = 0;
        while (x != 0) {
            int next = x % 10;
            if (abs(res) > INT_MAX / 10) return 0;
            res *= 10;
            res += next;
            x /= 10;
        }
        return res;
    }
};