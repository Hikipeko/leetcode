#include <vector>

using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int n = gas.size();
        int sum = 0, max = -1, index = 0;
        for (int i = 0; i < n; i++) {
            gas[i] -= cost[i];
            sum += gas[i];
            if (gas[i] > max) {
                max = 
            }
        }
    }
};