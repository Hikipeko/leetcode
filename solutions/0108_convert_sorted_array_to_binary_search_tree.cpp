#include <queue>
#include <vector>
#include <unordered_map>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:

    TreeNode* help(vector<int> & nums, int l, int r) {
        if (l >= r) return nullptr;
        int mid = (l + r) / 2;
        return new TreeNode(nums[mid], help(nums, l, mid), help(nums, mid + 1, r));
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return help(nums, 0, nums.size());
    }
};