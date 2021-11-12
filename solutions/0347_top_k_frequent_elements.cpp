#include <unordered_map>
#include <queue>
#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    struct OrderByCnt {
        bool operator()(const pair<int, int> &left, const pair<int, int> &right) {
            return left.second > right.second;
        }
    };

    vector<int> topKFrequent(vector<int> &nums, int k) {
        unordered_map<int, int> map;
        priority_queue<pair<int, int>, vector<pair<int, int>>, OrderByCnt> pq; // num, cnt
        for (int &n : nums) {
            map[n]++;
        }
        for (auto &it : map) {
            pq.push(it);
            if (pq.size() > k) pq.pop();
        }
        vector<int> result;
        while (!pq.empty()) {
            result.push_back(pq.top().first);
            pq.pop();
        }
        return result;
    }
};

int main() {
    vector<int> nums = {1, 1, 1, 2, 2, 3};
    Solution sol;
    vector<int> result = sol.topKFrequent(nums, 2);
    for (auto i:result) cout << i << endl;
}

