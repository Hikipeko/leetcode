#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() == 1) return 0;
        int min = prices[0];
        int res = 0;
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] - min > res) res = prices[i] - min;
            if (prices[i] < min) min = prices[i];
        }
        return res;
    }
};