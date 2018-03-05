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
        ListNode* cur = new ListNode(0);
        cur->next = head;
        ListNode* ans = cur;
        ListNode* p = cur;
        ListNode* q = p->next;
        while (q != nullptr && q->val < x) {
            cur = q;
            p = q;
            q = q->next;
        }
        while (q != nullptr) {
            if (q->val >= x) {
                p = p->next;
                q = q->next;
                continue;
            }
            p->next = q->next;
            q->next = cur->next;
            cur->next = q;
            cur = cur->next;
            q = p->next;
        }
        return ans->next;
    }
};