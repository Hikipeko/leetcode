#include <unordered_set>

using namespace std;

class Solution {
public:
    unordered_set<int> s;
    bool isHappy(int n) {
        if (s.find(n) != s.end()) return false;
        else s.insert(n);
        if (n == 1) return true;
        int next = 0;
        while (n) {
            int b = n % 10;
            next += b * b;
            n = n / 10;
        }
        return isHappy(next);
    }
};