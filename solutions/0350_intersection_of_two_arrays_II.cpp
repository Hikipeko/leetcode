#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> m;
        for (auto i : nums1) m[i]++;
        vector<int> res;
        for (auto i : nums2) {
            auto it = m.find(i);
            if (it != m.end()) {
                it->second--;
                res.push_back(i);
                if (it->second == 0) m.erase(it);
            }
        }
        return res;
    }
};