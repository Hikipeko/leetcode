#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        vector<char> stack;
        for (char ch : s) {
            if (ch == '(' || ch == '[' || ch == '{') stack.push_back(ch);
            else if (ch == ')') {
                if (stack.empty() || stack.back() != '(') return false;
                else stack.pop_back();
            } else if (ch == ']') {
                if (stack.empty() || stack.back() != '[') return false;
                else stack.pop_back();
            } else if (ch == '}') {
                if (stack.empty() || stack.back() != '{') return false;
                else stack.pop_back();
            }
        }
        return stack.empty();
    }
};