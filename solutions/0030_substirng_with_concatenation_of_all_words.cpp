// sliding window, hash table
# include <vector>
# include <string>
# include <unordered_map>

using namespace std;

class Solution {
public:
    unordered_map<string, int> word_count;
    int match = 0;
    unordered_map<string, int> temp_count;

    vector<int> findSubstring(string s, vector<string>& words) {
        int wl = words[0].length(), wc = words.size(), n = s.length();
        vector<int> res;
        for (string w : words) word_count[w]++;
        for (int i = 0; i < wl; i++) {
            match = 0;
            temp_count.clear();
            for (int j = 0; j < wc; j++) {
                add_word(s.substr(i + j * wl, wl));
            }
            if (match == wc) res.push_back(i);
            for (int j = i; j + (wc + 1) * wl < n; j+= wl) {
                add_word(s.substr(j + wc * wl, wl));
                remove_word(s.substr(j, wl));
                if (match == wc) res.push_back(j + wl);
            }
        }
        return res;
    }
    void add_word(string s) {
        if (word_count.count(s)) {
            if (++temp_count[s] <= word_count[s]) match++;
        }
    }

    void remove_word(string s) {
        if (word_count.count(s)) {
            if (--temp_count[s] < word_count[s]) match--;
        }
    }
};
