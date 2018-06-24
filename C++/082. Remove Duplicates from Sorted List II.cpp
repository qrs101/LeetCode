#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* p = head;
        ListNode* q = new ListNode(0);
        ListNode* ans = q;
        q->next = p;
        while (p != nullptr) {
            if (p->next != nullptr && p->val == p->next->val) {
                while (p->next != nullptr && p->val == p->next->val)
                    p->next = p->next->next;
                p = p->next;
                q->next = p;
            } else {
                q = q->next;
                p = p->next;
            }
        }
        return ans->next;
    }
};