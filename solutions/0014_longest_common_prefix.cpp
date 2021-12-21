#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty() || strs[0].empty()) return "";
        string res;
        int i = 0;
        while (i < strs[0].size()) {
            bool same = true;
            char ch = strs[0][i];
            for (int j = 1; j < strs.size(); j++) {
                if (strs[j].size() < i + 1 || strs[j][i] != ch) {
                    same = false;
                    break;
                }
            }
            if (!same) break;
            res = res + ch;
            i++;
        }
        return res;
    }
};