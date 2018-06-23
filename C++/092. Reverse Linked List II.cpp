#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        ListNode* ans = new ListNode(0);
        ans->next = head;
        ListNode* p_pre = ans;
        ListNode* p = head;
        ListNode* q = head;
        int i = m, j = n;
        while (j > 1) {
            if (i > 1) {
                p_pre = p_pre->next;
                p = p->next;
                i--;
            }
            q = q->next;
            j--;
        }
        i = n - m;
        while (i > 0) {
            p_pre->next = p->next;
            p->next = q->next;
            q->next = p;
            p = p_pre->next;
            i--;
        }
        return ans->next;
    }
};