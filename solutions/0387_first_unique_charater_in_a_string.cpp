#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    int firstUniqChar(string s) {
        unordered_map<char, short> m;
        for (char ch : s) m[ch]++;
        for (int i = 0; i < s.size(); i++) if (m[s[i]] == 1) return i;
        return -1;
    }
};