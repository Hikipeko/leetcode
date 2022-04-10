#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

class Solution {
public:
    struct Compare {
        bool operator()(const int ln, const int rn) {
            string l = to_string(ln), r = to_string(rn);
            return (l + r) > (r + l);
        }
    };

    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), Compare());
        string res = "";
        for (auto i : nums) res += to_string(i);
        return res[0] == '0' ? "0" : res;
    }
};

