#include <vector>

using namespace std;

class Solution {
public:
    bool abslarger(int x, int y) {
        x = (x > 0) ? x : -x;
        y = (y > 0) ? y : -y;
        return x > y;
    }

    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 0);
        int zero = -1;
        int p = 1;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0 && zero == -1) zero = i;
            else p *= nums[i];
        }
        if (zero != -1) {
            res[zero] = p;
            return res;
        }
        int max = 1, index = -1;
        p = 1;
        for (int i = 0; i < n; i++) {
            if (abslarger(nums[i], max)) {
                p *= max;
                max = nums[i];
                index = i;
            } else {
                p *= nums[i];
            }
        }
        for (int i = 0; i < n; i++) {
            if (index == i) res[i] = p;
            else res[i] = (p / nums[i]) * max;
        }
        return res;
    }
};