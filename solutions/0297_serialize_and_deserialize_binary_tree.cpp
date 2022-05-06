// binary tree DFS / BFS

#include <vector>
#include <string>
#include <sstream>

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        ostringstream res;
        serialize(root, res);
        return res.str();
    }

    void serialize(TreeNode* root, ostringstream& res) {
        if (!root) {
            res << "x ";
        } else {
            res << root->val << ' ';
            serialize(root->left, res);
            serialize(root->right, res);
        }
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        istringstream in(data);
        return deserialize(in);
    }

    TreeNode* deserialize(istringstream &in) {
        string val;
        in >> val;
        if (val == "x") return nullptr;
        TreeNode* temp = new TreeNode(stoi(val));
        temp->left = deserialize(in);
        temp->right = deserialize(in);
        return temp;
    }
};