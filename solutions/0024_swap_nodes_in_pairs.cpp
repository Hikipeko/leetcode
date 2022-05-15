struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode *first = head, *second = head->next, *res = second;
        while (true) {
            ListNode *third = second->next;
            second->next = first;
            if (!third) {
                first->next = nullptr;
                break;
            } else if (!third->next) {
                first->next = third;
                break;
            } else {
                ListNode *fourth = third->next;
                first->next = fourth;
                first = third;
                second = fourth;
            }
        }
        return res;
    }
};