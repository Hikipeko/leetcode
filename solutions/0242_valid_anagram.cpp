#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        char v[26] = {0};
        for (char c : s) v[c - 'a']++;
        for (char c : t) v[c - 'a']--;
        for (int i : v) if (i != 0) return false;
        return true;
    }
};
