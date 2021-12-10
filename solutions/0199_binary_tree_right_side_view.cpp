#include <vector>
#include <queue>

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
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (!root) return res;
        queue<TreeNode *> q;
        q.push(root);
        int levelSize = 1;
        int nextLevelSize = 0;
        while (!q.empty()) {
            TreeNode * curr = q.front();
            q.pop();
            if (curr->left) {
                nextLevelSize++;
                q.push(curr->left);
            }
            if (curr->right) {
                nextLevelSize++;
                q.push(curr->right);
            }
            levelSize--;
            if (levelSize == 0) {
                res.push_back(curr->val);
                levelSize = nextLevelSize;
                nextLevelSize = 0;
            }
        }
        return res;
    }
};
