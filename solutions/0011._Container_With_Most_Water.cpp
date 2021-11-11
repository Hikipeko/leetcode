#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int maxArea(vector<int> &height) {
        int start = 0, end = height.size(), max = 0;
        while (start < end) {
            int l = height[start], r = height[end];
            int size = (end - start) * (l < r ? l : r);
            if (size > max) max = size;
            (height[start] < height[end]) ? start++ : end--;
        }
        return max;
    }
};

int main() {
    vector<int> nums = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    Solution sol;
    cout << sol.maxArea(nums) << endl;
}