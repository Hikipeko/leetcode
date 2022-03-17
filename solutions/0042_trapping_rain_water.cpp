#include <vector>

using namespace std;

// dynamic programming
class Solution {
public:
    int trap(vector<int> &height) {
        int n = height.size();
        if (n <= 2) return 0;
        vector<int> lm = height;
        vector<int> rm = height;
        for (int i = 1; i < n; i++)
            lm[i] = (lm[i] > lm[i - 1]) ? lm[i] : lm[i - 1];
        for (int i = n - 3; i >= 0; i--)
            rm[i] = (rm[i] > rm[i + 1]) ? rm[i] : rm[i + 1];
        int res = 0;
        for (int i = 1; i < n - 1; i++) {
            int min = (lm[i] < rm [i]) ? lm[i] : rm[i];
            if (min > height[i]) res += (min - height[i]);
        }
        return res;
    }
};
