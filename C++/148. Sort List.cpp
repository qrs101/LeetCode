#include<iostream>
#include<climits>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;

        ListNode *res = new ListNode(INT_MIN);
        res->next = head;
        ListNode *p = res, *q = res;
        for (;q != nullptr && q->next != nullptr; p = p->next, q = q->next->next);
        q = p->next;
        p->next = nullptr;
        p = head;

        p = sortList(p);
        q = sortList(q);

        ListNode *t = res;

        while (p != nullptr || q != nullptr) {
            if (p == nullptr) {
                t->next = q;
                t = t->next;
                q = q->next;
            } else if (q == nullptr) {
                t->next = p;
                t = t->next;
                p = p->next;
            } else if (p->val < q->val) {
                t->next = p;
                t = t->next;
                p = p->next;
            } else {
                t->next = q;
                t = t->next;
                q = q->next;
            }
        }
        t = res->next;
        delete(res);
        return t;
    }
};