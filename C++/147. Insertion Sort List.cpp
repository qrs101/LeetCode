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
    ListNode* insertionSortList(ListNode* head) {
        ListNode *res = new ListNode(INT_MIN);
        res->next = head;
        ListNode *p = head;
        while (p != nullptr) {
            if (p->next != nullptr && p->next->val < p->val) {
                ListNode *q;
                for (q = res; q->next->val <= p->next->val; q = q->next);
                ListNode *t = p->next->next;
                p->next->next = q->next;
                q->next = p->next;
                p->next = t;
            } else {
                p = p->next;
            }
        }
        return res->next;
    }
};