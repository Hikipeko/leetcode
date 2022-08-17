// bfs https://grandyang.com/leetcode/126/
#include <vector>
#include <string>
#include <queue>
#include <unordered_set>
#include <climits>

using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict(wordList.begin(), wordList.end());
        vector<vector<string>> res;
        vector<string> p;
        p.push_back(beginWord);
        queue<vector<string>> paths;
        paths.push(p);
        // the words currently reached by the bfs tree
        unordered_set<string> words;
        int level = 1, minLevel = INT_MAX;
        while (!paths.empty()) {
            auto t = paths.front();
            paths.pop();
            if (t.size() > level) {
                if (++level > minLevel) break;
                for (string w : words) dict.erase(w);
                words.clear();
            }
            string last = t.back();
            for (int i = 0; i < last.length(); i++) {
                string newLast = last;
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    newLast[i] = ch;
                    if (!dict.count(newLast)) continue;
                    // next found
                    words.insert(newLast);
                    vector<string> nextPath = t;
                    nextPath.push_back(newLast);
                    if (newLast == endWord) {
                        res.push_back(nextPath);
                        minLevel = level;
                    } else {
                        paths.push(nextPath);
                    }
                }
            }
        }
        return res;
    }
};
