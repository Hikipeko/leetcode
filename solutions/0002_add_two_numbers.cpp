
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        int val = l1->val + l2->val;
        int overflow = val / 10;
        auto *res = new ListNode(val % 10);
        auto *curr = res;
        while (l1->next && l2->next) {
            l1 = l1->next;
            l2 = l2->next;
            val = l1->val + l2->val + overflow;
            overflow = val / 10;
            curr->next = new ListNode(val % 10);
            curr = curr->next;
        }
        while (l1->next) {
            l1 = l1->next;
            val = l1->val + overflow;
            overflow = val / 10;
            curr->next = new ListNode(val % 10);
            curr = curr->next;
        }

        while (l2->next) {
            l2 = l2->next;
            val = l2->val + overflow;
            overflow = val / 10;
            curr->next = new ListNode(val % 10);
            curr = curr->next;
        }
        if (overflow == 1) curr->next = new ListNode(1);
        return res;
    }
};