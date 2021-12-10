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
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        depth(root, res);
        return res;
    }

    int depth(TreeNode* root, int &res) {
        if (!root) return 0;
        int left = depth(root->left,res);
        int right = depth(root->right,res);
        res = max(res, left + right);
        return max(left, right) + 1;
    }

    int max(int l, int r) {return l > r ? l : r;}

};