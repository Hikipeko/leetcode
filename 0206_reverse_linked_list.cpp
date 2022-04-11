class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head) return head;
        if (!head->next) return head;
        ListNode* next = head->next;
        head->next = nullptr;
        while (next) {
            ListNode* temp = next->next;
            next->next = head;
            head = next;
            next = temp;
        }
        return head;
    }
};