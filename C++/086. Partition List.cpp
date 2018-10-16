#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *res = new ListNode(0);
        res->next = head;
        for (ListNode *p = res, *q = res; q->next != nullptr; ) {
            if (q->next->val >= x) {
                q = q->next;
                continue;
            }
            if (p == q) {
                p = p->next;
                q = q->next;
                continue;
            }
            ListNode *tmp = q->next;
            q->next = tmp->next;
            tmp->next = p->next;
            p->next = tmp;
            p = p->next;
        }
        return res->next;
    }
};