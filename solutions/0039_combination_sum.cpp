#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> res;
    vector<int> can;
    vector<int> temp;
    int sum;
    int max;

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        res.clear();
        temp.clear();
        can = candidates;
        sum = target;
        max = candidates.size() - 1;
        help();
        return res;
    }

    void help() {
        if (sum < 0) return;
        if (sum == 0) {
            res.push_back(temp);
            return;
        }
        for (int i = max; i >= 0; i--) {
            int dummy = max;
            sum -= can[i];
            max = i;
            temp.push_back(can[i]);
            help();
            temp.pop_back();
            max = dummy;
            sum += can[i];
        }
    }
};
