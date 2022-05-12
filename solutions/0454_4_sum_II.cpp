#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int, int> m;
        int res = 0;
        for (auto i : nums1)
            for (auto j : nums2)
                m[i + j] ++;
        for (auto i : nums3) {
            for (auto j : nums4) {
                auto it = m.find(-i - j);
                if (it != m.end()) {
                    res += it->second;
                }
            }
        }
        return res;
    }
};