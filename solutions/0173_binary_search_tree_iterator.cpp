#include <vector>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        while (root) {
            path.push_back(root);
            root = root->left;
        }
    }

    int next() {
        int res = path.back()->val;
        TreeNode* curr = path.back();
        if (curr->right) {
            path.pop_back();
            curr = curr->right;
            while (curr) {
                path.push_back(curr);
                curr = curr->left;
            }
        } else {
            path.pop_back();
        }
        return res;
    }

    bool hasNext() {
        return !path.empty();
    }

private:
    vector<TreeNode *> path;
};