using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
            : val(_val), left(_left), right(_right), next(_next) {}
};


class Solution {
public:
    Node* connect(Node* root) {
        if (!root) return root;
        connect(root->left);
        connect(root->right);
        Node* l = root->left, *r = root->right;
        while (l && r) {
            l->next = r;
            l = l->right;
            r = r->left;
        }
        return root;
    }
};