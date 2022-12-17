struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *reverseKGroup(ListNode *head, int k) {
        // Find the length of the linked list
        if (k == 1) return head;
        int length = 0;
        ListNode *curr = head;
        while (curr != nullptr) {
            length++;
            curr = curr->next;
        }
        if (k > length) return head;

        // Reverse group by group
        ListNode *tail = nullptr, *prev = head;
        ListNode *new_head = reverseGroup(head, &tail, k);
        ListNode *res = tail;
        for (int i = 1; i < length / k; i++) {
            head = new_head;
            new_head = reverseGroup(head, &tail, k);
            prev->next = tail;
            prev = head;
        }
        prev->next = new_head;
        return res;
    }

    // Reverse a single group
    // Return the first node (head) of next group (old head becomes tail)
    ListNode *reverseGroup(ListNode *head, ListNode **tail, int k) {
        ListNode *prev = head, *curr = head->next, *next = curr->next;
        for (int i = 2; i < k; i++) {
            curr->next = prev;
            prev = curr;
            curr = next;
            next = next->next;
        }
        curr->next = prev;
        *tail = curr;
        return next;
    }
};

int main() {
    ListNode *head = new ListNode(1, new ListNode(2, new
            ListNode(3, new ListNode(4, new ListNode(5)))));
    Solution s;
    s.reverseKGroup(head, 2);
}
