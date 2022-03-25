#include <vector>

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int d = matrix.size();
        int r = matrix[0].size();
        int l = 0, u = 0, x = 0, y = 0;
        while (true) {
            while (y < r - 1) res.push_back(matrix[x][y++]);
            if (++u > d) break;
            while (x < d - 1) res.push_back(matrix[x++][y]);
            if (--r < l) break;
            while (y > l) res.push_back(matrix[x][y--]);
            if (--d < u) break;
            while (x > u) res.push_back(matrix[x--][y]);
            if (++l > r) break;
        }
        res.push_back(matrix[x][y]);
        return res;
    }
};