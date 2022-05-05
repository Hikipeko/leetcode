#include <vector>

using namespace std;

// 0: dead, 1: life, 2: dead -> dead, 3: dead-> life, 4: life -> dead, 5: life ->life
class Solution {
public:
    int max(int i, int j) { return i > j ? i : j; }

    int min(int i, int j) { return i < j ? i : j; }

    int numLife(const vector<vector<int>> &board, int i, int j) {
        int res = 0;
        for (int k = max(i - 1, 0); k < min(i + 2, board.size()); k++) {
            for (int l = max(j - 1, 0); l < min(j + 2, board[0].size()); l++) {
                if (k == i && l == j) continue;
                int s = board[k][l];
                if (s == 1 || s == 4 || s == 5) res++;
            }
        }
        return res;
    }

    void gameOfLife(vector<vector<int>> &board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                int num = numLife(board, i, j);
                if (board[i][j] == 1)
                    board[i][j] = (num == 2 || num == 3) ? 5 : 4;
                else if (num == 3)
                    board[i][j] = 3;
                else
                    board[i][j] = 2;
            }
        }
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                int s = board[i][j];
                board[i][j] = (s == 2 || s == 4) ? 0 : 1;
            }
        }
    }
};

class Solution_ {
public:
    void gameOfLife(vector<vector<int> > &board) {
        int m = board.size(), n = m ? board[0].size() : 0;
        vector<int> dx{-1, -1, -1, 0, 1, 1, 1, 0};
        vector<int> dy{-1, 0, 1, 1, 1, 0, -1, -1};
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int cnt = 0;
                for (int k = 0; k < 8; ++k) {
                    int x = i + dx[k], y = j + dy[k];
                    if (x >= 0 && x < m && y >= 0 && y < n && (board[x][y] == 1 || board[x][y] == 2)) {
                        ++cnt;
                    }
                }
                if (board[i][j] && (cnt < 2 || cnt > 3)) board[i][j] = 2;
                else if (!board[i][j] && cnt == 3) board[i][j] = 3;
            }
        }
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                board[i][j] %= 2;
            }
        }
    }
};