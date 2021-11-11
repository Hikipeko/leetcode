#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &nums) {
        int maj = nums[0];
        int cnt = 1;
        for (auto i = 1; i < nums.size(); i++) {
            if (nums[i] == maj) cnt++;
            else if (cnt != 0) cnt--;
            else {
                cnt = 1;
                maj = nums[i];
            }
        }
        return maj;
    }
};

int main() {
    vector<int> nums = {3, 2, 3};
    Solution sol;
    cout << sol.majorityElement(nums) << endl;
}