// dp
#include <string>

using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n == 1) return (s[0] == '0') ? 0 : 1;
        if (s[0] == '0') return 0;
        int eo = (s[1] == '0') ? 0 : 1;
        int et = 0;
        if (valid(s[0], s[1])) et++;
        for (int i = 2; i < s.size(); i++) {
            int eon = (s[i] == '0') ? 0 : eo + et;
            int etn = valid(s[i - 1], s[i]) ? eo : 0;
            eo = eon;
            et = etn;
        }
        return eo + et;
    }

    bool valid(char c1, char c2) {
        int a = c1 - '0';
        int b = c2 - '0';
        return (a == 1) || (a == 2 && b <= 6);
    }
};