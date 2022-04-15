#include <vector>

using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> res;
        vector<vector<int>> g(numCourses, vector<int>());
        vector<int> id(numCourses, 0);
        for (auto &v : prerequisites) {
            g[v[1]].push_back(v[0]);
            id[v[0]]++;
        }
        vector<int> top;
        int cnt = 0;
        for (int i = 0; i < numCourses; i++) {
            if (id[i] == 0) {
                top.push_back(i);
                res.push_back(i);
                cnt++;
            }
        }
        while (!top.empty()) {
            int curr = top.back();
            top.pop_back();
            for (int i = 0; i < g[curr].size(); i++) {
                if (--id[g[curr][i]] == 0) {
                    top.push_back(g[curr][i]);
                    res.push_back(g[curr][i]);
                    cnt++;
                }
            }
        }
        if (cnt == numCourses) return res;
        else return vector<int>();
    }
};
