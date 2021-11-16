#include <vector>
#include <unordered_map>
#include <algorithm>

// map, sliding window

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        bool contain[256] = {false};
        int res = 0, it1 = 0, it2 = 0, n = s.length();
        while (it2 != n) {
            while (it2 != n && !contain[s[it2]]) {
                contain[s[it2]] = true;
                it2++;
            }
            if (it2 - it1 > res) res = it2 - it1;
            while (contain[s[it2]]) {
                contain[s[it1]] = false;
                it1++;
            }
        }
        return res;
    }
};