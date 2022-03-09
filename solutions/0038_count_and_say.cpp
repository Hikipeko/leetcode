#include <string>
#include <iostream>

using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        if (n == 1) return "1";
        string temp = countAndSay(n - 1);
        char curr = temp[0];
        int cnt = 1;
        string res;
        for (int i = 1; i < temp.size(); i++) {
            if (temp[i] == curr) {
                cnt++;
            } else {
                res.push_back(char(cnt + '0'));
                res.push_back(curr);
                curr = temp[i];
                cnt = 1;
            }
        }
        res.push_back(char(cnt + '0'));
        res.push_back(curr);
        return res;
    }
};

int main() {
    Solution s;
    for (int i = 1; i < 40; i++)
        cout << s.countAndSay(i) << endl;
    return 0;
}