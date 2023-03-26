#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        // greedy algorithm
        vector<string> symbols{"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        vector<int> values{1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        int i = 0;
        string res = "";
        while (num != 0) {
            if (num < values[i]) {
                i++;
            } else {
                num -= values[i];
                res += symbols[i];
            }
        }
        return res;
    }
};