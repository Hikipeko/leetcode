#include<cstdlib>
#include<climits>
#include<iostream>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        bool neg = dividend > 0 ^ divisor > 0;
        long m = labs(dividend);
        cout << m;
        long n = labs(divisor);
        // m/n
        long res = neg ? -help(m, n) : help(m, n);
        return res > INT_MAX? INT_MAX : res;
    }

    long help(long m, long n) {
        if (n > m) return 0;
        long p = 1, t = n;
        while ((t << 1) < m) {
            p = p << 1;
            t = t << 1;
        }
        return p + help(m - t, n);
    }
};

int main() {
    Solution s;
    s.divide(-2147483648, -1);
}