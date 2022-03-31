#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int sum = 0, total = 0, res = -1;
        for (int i = 0; i < n; i++) {
            gas[i] -= cost[i];
            total += gas[i];
            sum += gas[i];
            if (sum < 0) {
                res = i + 1;
                sum = 0;
            }
        }
        return total < 0 ? -1 : res;
    }
};