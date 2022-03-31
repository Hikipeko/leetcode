#include <string>

using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        string str;
        for (char ch : s) {
            if (!isalnum(ch)) continue;
            if (ch >= 'A' && ch <= 'Z')
                ch = ch - 'A' + 'a';
            str.push_back(ch);
        }
        for (int i = 0; i < str.size() / 2; i++) {
            if (str[i] != str[str.size() - 1 - i]) return false;
        }
        return true;
    }
};