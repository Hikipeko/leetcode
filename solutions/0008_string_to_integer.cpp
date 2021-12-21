#include <string>
#include <climits>

using namespace std;

class Solution {
public:
    int myAtoi(string s) {
        int res = 0, i = 0;
        bool negative = false;
        for (; i < s.size(); i++) {
            char ch = s[i];
            if (isspace(ch)) continue;
            if (ch == '-') {
                i++;
                negative = true;
                break;
            } else if (ch == '+') {
                i++;
                break;
            }
            else break;
        }
        for (; i < s.size(); i++) {
            char ch = s[i];
            if (ch - '0' >= 0 && ch - '0' <= 9) {
                if (res > INT_MAX / 10 || (res == INT_MAX / 10 && ch - '0' > 7))
                    return negative ? -INT_MAX - 1 : INT_MAX;
                res = res * 10 - '0' + ch;
            } else break;
        }
        return negative ? -res : res;
    }
};