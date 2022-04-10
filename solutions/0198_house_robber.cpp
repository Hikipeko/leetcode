class Solution {
public:
    inline int max(int x, int y) {
        return x > y ? x : y;
    }
    int max(int x, int y, int z) {
        return max(max(x, y), z);
    }
    int rob(vector<int>& nums) {
        if (nums.size() == 1) return nums[0];
        if (nums.size() == 2) return max(nums[0], nums[1]);
        int x = nums[0], y = nums[1], z = nums[2];
        int res = max(x, y, z);
        for (int i = 3; i < nums.size(); i++) {
            int temp = max(x, y) + nums[i];
            x = y;
            y = z;
            z = temp;
            if (temp > res) res = temp;
        }
        return res;
    }
};