#include <vector>

using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res(1, vector<int>(1, 1));
        for (int i = 1; i < numRows; i++) {
            vector<int> next = vector<int>(1, 1);
            for (int j = 1; j < i; j++) {
                next.push_back(res[i - 1][j - 1] + res[i - 1][j]);
            }
            next.push_back(1);
            res.push_back(next);
        }
        return res;
    }
};