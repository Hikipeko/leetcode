#include <vector>
#include <string>

using namespace std;

class Solution {
private:
    int n;
    vector<string> res;
public:
    vector<string> generateParenthesis(int n_) {
        n = n_;
        genPerm("", 0, 0);
        return res;
    }

    void genPerm(string curr, int balance, int num) {
        if (curr.size() == 2 * n) {
            res.push_back(curr);
            return;
        }
        if (num < n) genPerm(curr + '(', balance + 1, num + 1);
        if (balance > 0) genPerm(curr + ')', balance - 1, num);
    }
};