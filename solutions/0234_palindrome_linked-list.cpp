struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

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

    bool isPalindrome(ListNode *head) {
        if (!head || !head->next) return true;
        ListNode *fast = head, *slow = head;
        while (fast->next && fast->next->next) {
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode *l2 = reverseList(slow);
        while (l2 && head) {
            if (l2->val != head->val) return false;
            l2 = l2->next;
            head = head->next;
        }
        return true;
    }
};