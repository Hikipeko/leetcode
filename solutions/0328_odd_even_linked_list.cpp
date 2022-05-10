struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return head;
        ListNode* prev = head, *curr = head->next, *next = head->next->next;
        ListNode* head2 = curr;
        bool odd = false;
        while (next) {
            prev->next = next;
            prev = curr;
            curr = next;
            next = next->next;
            odd = !odd;
        }
        if (odd) {
            prev->next = nullptr;
            curr->next = head2;
        } else {
            prev->next = head2;
            curr->next = nullptr;
        }
        return head;
    }
};