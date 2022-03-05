#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int search(vector<int> &nums, int target) {
        int l = 0, r = nums.size()-1;
        while (l <= r) {
            int m = (r + l) / 2;
            if (nums[m] == target) return m;
            if (nums[m] > nums[r]) {
                if (nums[l] <= target && target < nums[m]) r = m - 1;
                else l = m + 1;
            } else {
                if (nums[m] < target && nums[r] >= target) l = m + 1;
                else r = m - 1;
            }
        }
        return -1;
    }
};

int main() {
    Solution s;
    vector<int> v = {1,3};
    cout << s.search(v, 3);
}