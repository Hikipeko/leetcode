#include <vector>

using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // valid box
        for (int i = 0; i < 9; i+= 3) {
            for (int j = 0; j < 9; j += 3) {
                vector<bool> v(9, false);
                for (int k = 0; k < 3; k++) {
                    for (int l = 0; l < 3; l++) {
                        char ch = board[i+k][j+l];
                        if (ch != '.') {
                            if (v[int(ch - '1')]) return false;
                            else v[int(ch - '1')] = true;
                        }
                    }
                }
            }
        }
        // valid line
        for (int i = 0; i < 9; i++) {
            vector<bool> v(9, false);
            for (int j = 0; j < 9; j++) {
                char ch = board[i][j];
                if (ch != '.') {
                    if (v[int(ch - '1')]) return false;
                    else v[int(ch - '1')] = true;
                }
            }
        }
        // valid column
        for (int i = 0; i < 9; i++) {
            vector<bool> v(9, false);
            for (int j = 0; j < 9; j++) {
                char ch = board[j][i];
                if (ch != '.') {
                    if (v[int(ch - '1')]) return false;
                    else v[int(ch - '1')] = true;
                }
            }
        }
        return true;
    }
};