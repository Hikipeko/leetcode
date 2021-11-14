#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <numeric>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        unordered_map<string, vector<int>> map;
        for (int i = 0; i < strs.size(); i++) {
            string temp = strs[i];
            sort(temp.begin(), temp.end());
            map[temp].push_back(i);
        }
        vector<vector<string>> res;
        res.resize(map.size());
        int i = 0;
        for (auto &it: map) {
            for (int j : it.second)
                res[i].push_back(strs[j]);
            i++;
        }
        return res;
    }
};

