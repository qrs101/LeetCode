#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (k == 0 || head == nullptr)
            return head;
        ListNode *p, *q;
        int n;
        for (n = 0, p = head; p != nullptr; n++, p = p->next);
        k = k % n;
        ListNode *res = new ListNode(0);
        res->next = head;
        p = res, q = res;
        for (int i = 0; i < k; i++, q = q->next);
        for (; q->next != nullptr; p = p->next, q = q->next);
        q->next = res->next;
        res->next = p->next;
        p->next = nullptr;
        return res->next;
    }
};