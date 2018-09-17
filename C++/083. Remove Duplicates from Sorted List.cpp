#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* res = new ListNode(0);
        res->next = head;
        for (ListNode *p = head, *q = head; q != nullptr; p->next = q, p = q) {
            for (q = q->next; q != nullptr && q->val == p->val; q = q->next);
        }
        return res->next;
    }
};