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
        int num = 1;
        for (ListNode *p = res, *q = head; q != nullptr; q = q->next) {
            for (; q->next != nullptr && q->next->val == q->val; q = q->next, num++);
            if (num > 1) {
                p->next = q->next;
                num = 1;
            } else {
                p = q;
            }
        }
        return res->next;
    }
};