#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.empty()) return intervals;
        sort(intervals.begin(), intervals.end(),
             [](const vector<int> &l, const vector<int> &r)
             {return l.front() < r.front();});
        vector<vector<int>> result = {intervals[0]};
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] > result.back()[1])
                result.push_back(intervals[i]);
            else
                result.back()[1] = intervals[i][1] < result.back()[1] ? result.back()[1] : intervals[i][1];
        }
        return result;
    }
};
