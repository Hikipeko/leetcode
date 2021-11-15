#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef vector<int> point;

class Solution {
public:
    struct Order {
        bool operator()(point &l, point &r) {
            return l[0] * l[0] + l[1] * l[1] < r[0] * r[0] + r[1] * r[1];
        }
    };

//    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
//        priority_queue<point, vector<point>, Order> pq;
//        for (auto &p : points) {
//            pq.push(p);
//            if (pq.size() > k) pq.pop();
//        }
//        vector<point> res;
//        while (!pq.empty()) {
//            res.push_back(pq.top());
//            pq.pop();
//        }
//        return res;
//    }

    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(), points.end(), Order());
        return vector<point>(points.begin(), points.begin() + k);
    }
};