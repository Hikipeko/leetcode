#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;
        map<int, int> s;
        for (int i = 0; i < k; i++) s[nums[i]] += 1;
        res.push_back(s.rbegin()->first);
        for (int i = k; i < n; i++) {
            if (--s[nums[i - k]] == 0) s.erase(nums[i - k]);
            s[nums[i]] += 1;
            res.push_back(s.rbegin()->first);
        }
        return res;
    }
};