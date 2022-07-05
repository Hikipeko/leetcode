#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        int len = 1;
        int b = 0;
        for (int i = 1; i < n - 1; i++) {
            int prev = i - 1, next = i + 1;
            while (prev >= 0 && next < n && s[prev] == s[next]) {
                prev--;
                next++;
            }
            if (next - prev - 1 > len) {
                len = next - prev - 1;
                b = prev + 1;
            }
        }
        for (int i = 0; i < n - 1; i++) {
            int prev = i, next = i + 1;
            while (prev >= 0 && next < n && s[prev] == s[next]) {
                prev--;
                next++;
            }
            if (next - prev - 1 > len) {
                len = next - prev - 1;
                b = prev + 1;
            }
        }
        return s.substr(b, len);
    }
};
