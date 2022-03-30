#include <vector>
#include <climits>
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
    int max;

    int maxPathSum(TreeNode* root) {
        max = INT_MIN;
        helpMax(root);
        return max;
    }

    // returns the max path starting at the root, ending at a descendent node
    int helpMax(TreeNode* root) {
        if (root == nullptr) return 0;
        int l = helpMax(root->left);
        int r = helpMax(root->right);
        int res = l > r ? l : r;
        if (l + r + root->val > max) max = l + r + root->val;
        return (res + root->val > 0) ? res + root->val : 0;
    }
};