#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
public:
    struct P {
        int r;
        int c;
    };

    inline void helpSearch(int r, int c, vector<vector<char>> &board, vector<P> &s) {
        if (board[r][c] == 'O') {
            s.push_back({r, c});
        }
    }

    void solve(vector<vector<char>> &board) {
        int h = board.size(), w = board[0].size();
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                if (i != 0 && i != h - 1 && j != 0 && j != w - 1) continue;
                if (board[i][j] != 'O') continue;
                vector<P> search;
                search.push_back({i, j});
                while (!search.empty()) {
                    P p = search.back();
                    search.pop_back();
                    board[p.r][p.c] = 'S';
                    if (p.r + 1 != h && board[p.r + 1][p.c] == 'O')
                        search.push_back({p.r + 1, p.c});
                    if (p.r != 0 && board[p.r - 1][p.c] == 'O')
                        search.push_back({p.r - 1, p.c});
                    if (p.c + 1 != w && board[p.r][p.c + 1] == 'O')
                        search.push_back({p.r, p.c + 1});
                    if (p.c != 0 && board[p.r][p.c - 1] == 'O')
                        search.push_back({p.r, p.c - 1});
                }
            }
        }
        for (auto &row : board) {
            for (char &c : row) {
                if (c == 'O') c = 'X';
                else if (c == 'S') c = 'O';
            }
        }
    }
};

