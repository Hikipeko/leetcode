

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *prev = head, *curr = head;
        for (int i = 0; i < n; i++) {
            if (prev->next)
                prev = prev->next;
            else
                return head->next;
        }
        while (prev->next) {
            prev = prev->next;
            curr = curr->next;
        }
        curr->next = curr->next->next;
        return head;
    }
};