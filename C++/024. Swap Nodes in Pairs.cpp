#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        ListNode *res = new ListNode(0);
        res->next = head;
        ListNode *p = res;
        while (p->next != nullptr && p->next->next != nullptr) {
            ListNode *tmp = p->next;
            p->next = p->next->next;
            tmp->next = p->next->next;
            p->next->next = tmp;
            p = p->next->next;
        }
        return res->next;
    }
};