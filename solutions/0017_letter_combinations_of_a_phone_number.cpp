#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
private:
    int N;
    string d;
    vector<string> res;
    unordered_map<char, vector<char>> map;


public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return res;
        d = digits;
        N = digits.size();
        map['2'] = {'a', 'b', 'c'};
        map['3'] = {'d', 'e', 'f'};
        map['4'] = {'g', 'h', 'i'};
        map['5'] = {'j', 'k', 'l'};
        map['6'] = {'m', 'n', 'o'};
        map['7'] = {'p', 'q', 'r', 's'};
        map['8'] = {'t', 'u', 'v'};
        map['9'] = {'w', 'x', 'y', 'z'};
        string curr;
        genPerm(curr, 0);
        return res;
    }

    void genPerm(string curr, int currSize) {
        if (currSize == N) {
            res.push_back(curr);
            return;
        }
        auto v = map[d[currSize]];
        for (char ch : v) {
            genPerm(curr + ch, currSize + 1);
        }
    }
};