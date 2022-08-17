#include <vector>

using namespace std;

class Solution {
public:
    int m;
    int n;
    vector<pair<int, int>> xy = {{-1, 0},
                                 {1,  0},
                                 {0,  -1},
                                 {0,  1}};

    void rote(vector<vector<int>> &grid, int i, int j, int &cnt) {

        for (auto &p: xy) {
            int x = p.first + i, y = p.second + j;
            if (x >= 0 && x < m && y >= 0 && y < n) {
                if (grid[x][y] == 1) {
                    cnt++;
                    grid[x][y] = 3;
                }
            }
        }
    }

    int orangesRotting(vector<vector<int>> &grid) {
        int round = 0;
        bool flesh;
        m = grid.size(), n = grid[0].size();
        while (true) {
            int cnt = 0;
            flesh = false;
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == 2) rote(grid, i, j, cnt);
                }
            }
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (grid[i][j] == 3) grid[i][j] = 2;
                    if (grid[i][j] == 1) flesh = true;
                }
            }
            if (cnt == 0) break;
            round++;
        }
        return flesh ? -1 : round;
    }
};
