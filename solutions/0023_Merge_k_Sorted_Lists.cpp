#include <vector>
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
    ListNode *mergeKLists(vector<ListNode *> &lists) {
        if (lists.size() == 0) return nullptr;
        int end = lists.size() - 1;
        while (end != 0) {
            for (int i = 0; i * 2 < end; i++) {
                lists[i] = mergeTwoLists(lists[2 * i], lists[2 * i + 1]);
            }
            if (end % 2 == 0)
                lists[end / 2] = lists[end];
            end = end / 2;
        }
        return lists[0];
    }

    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        if (l1->val < l2->val) {
            l1->next = mergeTwoLists(l1->next, l2);
            return l1;
        } else {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
    }
};


int main() {
    vector<ListNode*> lists;
    lists.push_back(new ListNode(1, new ListNode(4, new ListNode(5))));
    lists.push_back(new ListNode(1, new ListNode(3, new ListNode(4))));
    lists.push_back(new ListNode(2, new ListNode(6, new ListNode(8))));
    Solution sol;
    ListNode* result = sol.mergeKLists(lists);
    while(result) {
        cout << result->val;
        result = result->next;
    }
}