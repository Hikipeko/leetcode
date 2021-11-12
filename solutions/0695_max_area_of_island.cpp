#include <unordered_set>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    struct P {
        int r;
        int c;
    };

    int maxAreaOfIsland(vector<vector<int>> &grid) {
        int max = 0;
        int h = grid.size(), w = grid[0].size();
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (grid[i][j] != 1) continue;
                int tempSize = 0;
                vector<P> search;
                search.push_back({i, j});
                while (!search.empty()) {
                    P p = search.back();
                    search.pop_back();
                    tempSize++;
                    if (p.r + 1 != h && grid[p.r + 1][p.c] == 1) {
                        search.push_back({p.r + 1, p.c});
                        grid[p.r + 1][p.c] = 2;
                    }
                    if (p.r != 0 && grid[p.r - 1][p.c] == 1) {
                        search.push_back({p.r - 1, p.c});
                        grid[p.r - 1][p.c] = 2;
                    }
                    if (p.c + 1 != w && grid[p.r][p.c + 1] == 1) {
                        search.push_back({p.r, p.c + 1});
                        grid[p.r][p.c + 1] = 2;
                    }
                    if (p.c != 0 && grid[p.r][p.c - 1] == 1) {
                        search.push_back({p.r, p.c - 1});
                        grid[p.r][p.c - 1] = 2;
                    }
                }
                max = max > tempSize ? max : tempSize;
            }
        }
        return max;
    }
};

int main() {
    vector<vector<int>> grid = {{1, 1, 0, 0, 0},
                                {1, 1, 0, 0, 0},
                                {0, 0, 0, 1, 1},
                                {0, 0, 0, 1, 1}};
    Solution sol;
    cout << sol.maxAreaOfIsland(grid) << endl;
}
