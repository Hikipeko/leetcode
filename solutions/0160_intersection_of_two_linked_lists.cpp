struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int l1 = 0, l2 = 0;
        ListNode *h1 = headA, *h2 = headB;
        while (h1) {
            l1++;
            h1 = h1->next;
        }
        while (h2) {
            l2++;
            h2 = h2->next;
        }
        if (l1 > l2) {
            for (int i = 0; i < l1 - l2; i++) headA = headA->next;
        } else {
            for (int i = 0; i < l2 - l1; i++) headB = headB->next;
        }
        while (headA) {
            if (headA == headB) return headA;
            headA = headA->next;
            headB = headB->next;
        }
        return nullptr;
    }
};