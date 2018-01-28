#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* p = head;
        ListNode* q = head;
        for (int i = 0; i < n; i++)
            q = q->next;
        if (q == nullptr) {
            q = head->next;
            delete(head);
            return q;
        }
        while (q->next != nullptr) {
            p = p->next;
            q = q->next;
        }
        q = p->next;
        p->next = q->next;
        delete(q);
        return head;
    }
};