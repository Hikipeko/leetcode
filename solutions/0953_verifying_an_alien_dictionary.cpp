#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

class Solution {
public:
    bool isAlienSorted(vector<string> &words, string order) {
        unordered_map<char, short> m;
        short i = 0;
        for (char ch : order) m[ch] = i++;
        for (auto j = 0; j < words.size() - 1; j++) {
            if (greater(words[j], words[j + 1], m)) return false;
        }
        return true;
    }

    inline bool greater(const string &l, const string &r, unordered_map<char, short> &m) {
        int size = (l.size() < r.size()) ? l.size() : r.size();
        for (int i = 0; i < size; i++) {
            if (m[l[i]] > m[r[i]]) return true;
            else if (m[l[i]] < m[r[i]]) return false;
        }
        if (l.size() > r.size()) return true;
        return false;
    }
};