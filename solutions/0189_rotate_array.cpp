#include <vector>
#include <iostream>

using namespace std;

class Solution {
public:
    int gcd(int a, int b) {
        if (b == 0) return a;
        if (b == 1) return 1;
        return gcd(b, a - b * (a / b));
    }
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;
        int d = gcd(n, k);
        for (int i = 0; i < d; i++) {
            int curr = i, next = i;
            int prev = nums[i];
            for (int j = 0; j < n / d - 1; j++) {
                next -= k;
                if (next < 0) next += n;
                nums[curr] = nums[next];
                curr = next;
            }
            nums[curr] = prev;
        }
    }
};