#include <queue>
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

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<TreeNode *> q;
        q.push(root);
        int levelSize = 1, nextLevelSize = 0;
        vector<int> currLevel;
        while (!q.empty()) {
            TreeNode *curr = q.front();
            q.pop();
            currLevel.push_back(curr->val);
            if (curr->left) {
                q.push(curr->left);
                nextLevelSize++;
            }
            if (curr->right) {
                q.push(curr->right);
                nextLevelSize++;
            }
            if (--levelSize == 0) {
                 res.push_back(currLevel);
                 currLevel.clear();
                 levelSize = nextLevelSize;
                 nextLevelSize = 0;
            }
        }
        return res;
    }
};