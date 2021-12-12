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
    int goodNodes(TreeNode* root) {
        int res = 0;
        help(root, res, -114514);
        return res;
    }

    void help(TreeNode* root, int &res, int max) {
        if (!root) return;
        if (root->val >= max) {
            res++;
            help(root->left, res, root->val);
            help(root->right, res, root->val);
        } else {
            help(root->left, res, max);
            help(root->right, res, max);
        }

    }
};