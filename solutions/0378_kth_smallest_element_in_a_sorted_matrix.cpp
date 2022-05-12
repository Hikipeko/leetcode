#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int l = matrix[0][0], r = matrix.back().back();
        while (l < r) {
            int m = l + (r - l) / 2, cnt = 0;
            for (auto &v : matrix) {
                cnt += (upper_bound(v.begin(), v.end(), m) - v.begin());
            }
            if (cnt < k) l = m + 1;
            else r = m;
        }
        return l;
    }
};