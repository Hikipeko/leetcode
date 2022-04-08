#include <string>

using namespace std;

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int curr = 0;
        for (char ch : columnTitle) {
            curr *= 26;
            curr += int(ch - 'A' + 1);
        }
        return curr;
    }
};