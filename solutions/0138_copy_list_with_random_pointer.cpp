#include <unordered_map>

using namespace std;

class Node {
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
public:
    Node *copyRandomList(Node *head) {
        unordered_map<Node *, Node *> old2new;
        old2new[nullptr] = nullptr;
        if (head == nullptr) return nullptr;
        Node *res = new Node(head->val);
        Node *curr = res, *old = head;
        while (old->next != nullptr) {
            old2new[old] = curr;
            old = old->next;
            curr->next = new Node(old->val);
            curr = curr->next;
        }
        old2new[old] = curr;
        old = head;
        curr = res;
        while (old != nullptr) {
            curr->random = old2new[old->random];
            curr = curr->next;
            old = old->next;
        }
        return res;
    }
};