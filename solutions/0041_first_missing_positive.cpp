#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        for (int &e : nums)
            if (e > n || e < 0) e = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] == n + 2) continue;
            if (nums[i] != 0) {
                int curr = nums[i];
                while (curr != 0 && curr != n + 2) {
                    int next = nums[curr - 1];
                    nums[curr - 1] = n + 2;
                    curr = next;
                }
            }
        }
        for (int i = 0; i < n; i++)
            if (nums[i] != n + 2) return i + 1;
        return n + 1;
    }
};

int main() {
    Solution s;
    vector<int> v(4);
    v[0] = 2;
    v[1] = 3;
    v[2] = 1;
    v[3] = 4;
    cout << s.firstMissingPositive(v);
}