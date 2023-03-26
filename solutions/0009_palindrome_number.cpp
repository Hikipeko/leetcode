#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x == 0) return true;
        if (x < 0 || x % 10 == 0) return false;
        int pal = 0;
        while (x > pal) {
            pal *= 10;
            pal += (x % 10);
            x /= 10;
        }
        return pal == x || (pal / 10) == x;
    }
};

int main() {
    Solution s;
    cout << s.isPalindrome(121) << endl;
}