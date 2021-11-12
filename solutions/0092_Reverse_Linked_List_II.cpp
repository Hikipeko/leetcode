#include <iostream>

using namespace std;
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (right - left == 0) return head;
        auto* dummy = new ListNode(0, head);
        ListNode* l_start = dummy;
        ListNode* next, *curr, *temp;
        int i = 1;
        for (; i < left; i++) l_start = l_start->next;
        curr = l_start->next;
        next = curr->next;
        for (; i < right; i++) {
            temp = next->next;
            next->next = curr;
            curr = next;
            next = temp;
        }
        l_start->next->next = next;
        l_start->next = curr;
        head = dummy->next;
        delete dummy;
        return head;
    }
};

int main() {
    auto* test = new ListNode(1, new ListNode(2));
    Solution sol;
    test = sol.reverseBetween(test, 1, 2);
    while (test) {
        cout  << test->val << endl;
        test = test->next;
    }
}