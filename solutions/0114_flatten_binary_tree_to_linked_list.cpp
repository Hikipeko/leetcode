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
    void flatten(TreeNode *root) {
        if (!root) return;
        if (root->left) flatten(root->left);
        if (root->right) flatten(root->right);
        TreeNode *tmp = root->right;
        root->right = root->left;
        root->left = nullptr;
        while (root->right) root = root->right;
        root->right = tmp;
    }

//    void flatten(TreeNode* root) {
//        if (!root) return;
//        help(root);
//    }
//
//    TreeNode* help(TreeNode* root) {
//        if (!root->left && !root->right) return root;
//        else if (!root->left) {
//            return help(root->right);
//        } else if (!root->right) {
//            root->right = root->left;
//            root->left = nullptr;
//            return help(root->right);
//        } else {
//            TreeNode *last = help(root->left);
//            TreeNode *temp = help(root->right);
//            last->right = root->right;
//            root->right = root->left;
//            root->left = nullptr;
//            return temp;
//        }
//    }
};
