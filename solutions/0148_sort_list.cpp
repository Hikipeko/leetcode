// merge sort
struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *sortList(ListNode *head) {
        if (!head) return nullptr;
        ListNode *curr = head;
        int cnt = 0;
        while (curr != nullptr) {
            cnt++;
            curr = curr->next;
        }
        if (cnt == 1) return head;
        curr = head;
        for (int i = 0; i < cnt / 2 - 1; i++)
            curr = curr->next;
        ListNode *second = curr->next;
        curr->next = nullptr;
        head = sortList(head);
        second = sortList(second);
        head = merge(head, second);
        return head;
    }

    ListNode *merge(ListNode *f, ListNode *s) {
        if (!f) return s;
        if (!s) return f;
        ListNode *res, *prev;
        if (f->val < s->val) {
            res = f;
            prev = f;
            f = f->next;
        } else {
            res = s;
            prev = s;
            s = s->next;
        }
        while (f || s) {
            if (!f) {
                prev->next = s;
                return res;
            } else if (!s) {
                prev->next = f;
                return res;
            } else if (f->val < s->val) {
                prev->next = f;
                prev = f;
                f = f->next;
            } else {
                prev->next = s;
                prev = s;
                s = s->next;
            }
        }
        return res;
    }
};

int main() {
    ListNode* head = new ListNode(4, new ListNode(2, new ListNode(1, new ListNode(3))));
    Solution s;
    s.sortList(head);
}