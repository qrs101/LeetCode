#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr)
            return l2;
        if (l2 == nullptr)
            return l1;
        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* head, * p;
        if (p1->val < p2->val) {
            head = p = p1;
            p1 = p1->next;
        } else {
            head = p = p2;
            p2 = p2->next;
        }
        while (p1 != nullptr && p2 != nullptr) {
            if (p1->val < p2->val) {
                p->next = p1;
                p1 = p1->next;
            } else {
                p->next = p2;
                p2 = p2->next;
            }
            p = p->next;
        }
        p1 == nullptr? p->next = p2 : p->next = p1;
        return head;
    }
};