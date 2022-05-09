#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> amount2num;

    int coinChange(vector<int>& coins, int amount) {
        vector<int> dummy(amount + 1, 0);
        swap(amount2num, dummy);
        return coinChange_help(coins, amount);
    }

    int coinChange_help(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        if (amount2num[amount] != 0) return amount2num[amount];
        // not in the map
        int res = -1;
        for (auto i : coins) {
            if (i == amount) {
                res = 1;
                break;
            } else if (amount > i) {
                int prev = coinChange_help(coins, amount - i);
                if (prev != -1) {
                    if (res == -1) res = prev + 1;
                    else if (prev + 1 < res) res = prev + 1;
                }
            }
        }
        amount2num[amount] = res;
        return res;
    }
};
