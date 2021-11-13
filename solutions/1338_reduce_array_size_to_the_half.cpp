#include <unordered_map>
#include <queue>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

typedef pair<int, int> cnt;

class Solution {
public:
    int minSetSize(vector<int> &arr) {
        unordered_map<int, int> map;
        vector<int> v;
        for (auto i : arr) map[i]++;
        for (auto &cnt : map) v.push_back(cnt.second);
        sort(v.begin(), v.end(), std::greater<int>());
        int sum = 0, res = 0;
        while (sum * 2 < arr.size())
            sum += v[res++];
        return res;
    }
};
