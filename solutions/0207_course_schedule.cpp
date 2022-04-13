#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses, vector<int>());
        vector<int> id(numCourses, 0);
        for (auto &v : prerequisites) {
            g[v[0]].push_back(v[1]);
            id[v[1]]++;
        }
        vector<int> top;
        int cnt = 0;
        for (int i = 0; i < numCourses; i++) {
            if (id[i] == 0) {
                top.push_back(i);
                cnt++;
            }
        }
        cout << cnt << endl;
        while (!top.empty()) {
            int curr = top.back();
            top.pop_back();
            for (int i = 0; i < g[curr].size(); i++) {
                if (--id[g[curr][i]] == 0) {
                    top.push_back(g[curr][i]);
                    cnt++;
                }
            }
        }
        cout << cnt << endl;
        return cnt == numCourses;
    }
};

int main() {
    Solution s;
    vector<vector<int>> v;
    v.push_back(vector<int>{1,0});
    s.canFinish(2, v);
}