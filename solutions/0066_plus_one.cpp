#include <vector>

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size() - 1;
        digits[n]++;
        while (n > 0 && digits[n] == 10) {
            digits[n] = 0;
            digits[--n]++;
        }
        if (digits[0] == 10) {
            digits[0] = 0;
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};