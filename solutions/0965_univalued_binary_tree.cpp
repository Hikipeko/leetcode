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
    bool isUnivalTree(TreeNode* root) {
        if (!root) return true;
        bool res = true;
        if (root->left) res = res && root->val == root->left->val;
        if (root->right) res = res && root->val == root->right->val;
        return res && isUnivalTree(root->left) && isUnivalTree(root->right);
    }
};