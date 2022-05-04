#include <vector>

using namespace std;

class Solution {
public:
    int numSquares(int n) {
        vector<int> v(n + 1);
        v[0] = 0;
        v[1] = 1;
        for (int i = 2; i <= n; i++) {
            int min = i;
            for (int j = 1; j * j <= i; j++) {
                int tmp = 1 + v[i - j * j];
                if (tmp < min) min = tmp;
            }
            v[i] = min;
        }
        return v[n];
    }
};