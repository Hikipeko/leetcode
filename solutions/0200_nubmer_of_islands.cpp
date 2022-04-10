#include <vector>

using namespace std;

class Solution {
public:
    void try_add(int i, int j, vector<vector<char>>& grid, vector<pair<int, int>> &s) {
        if (i < 0 || i >= grid.size()) return;
        if (j < 0 || j >= grid[0].size()) return;
        if (grid[i][j] == '1') {
            grid[i][j] = '2';
            s.emplace_back(i, j);
        } else
            return;
    }

    void bfs(int x, int y, vector<vector<char>>& grid) {
        grid[x][y] = '2';
        vector<pair<int, int>> s;
        s.emplace_back(x, y);
        while (!s.empty()) {
            auto p = s.back();
            s.pop_back();
            int i = p.first, j = p.second;
            try_add(i - 1, j, grid, s);
            try_add(i + 1, j, grid, s);
            try_add(i, j + 1, grid, s);
            try_add(i, j - 1, grid, s);
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int cnt = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == '1') {
                    cnt ++;
                    bfs(i, j, grid);
                }
            }
        }
        return cnt;
    }
};