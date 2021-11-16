#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


// idea: use unordered_map to create a one to one mapping A -> B
class Solution {
public:
    int romanToInt(string s) {
//        unordered_map<char, int> map;
//        map['I'] = 1;
//        map['V'] = 5;
//        map['X'] = 10;
//        map['L'] = 50;
//        map['C'] = 100;
//        map['D'] = 500;
//        map['M'] = 1000;
        unordered_map<char, int> map{{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};
        int sum = 0;
        for (int i = 0; i < s.length() - 1; i++) {
            if (map[s[i]] < map[s[i + 1]]) sum -= map[s[i]];
            else sum += map[s[i]];
        }
        return sum + map[s[s.length() - 1]];
    }
};