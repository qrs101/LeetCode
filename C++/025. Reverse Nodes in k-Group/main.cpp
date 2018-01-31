#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (k == 1 || head == nullptr)
            return head;
        int i;
        ListNode* q2 = head;
        for (i = 1; i < k && q2->next != nullptr; i++, q2 = q2->next);
        if (i != k)
            return head;
        ListNode* res = q2;
        ListNode* p1 = head;
        ListNode* p2 = head;
        ListNode* p3 = p2->next;
        ListNode* q1 = q2->next;
        q2 = q1;
        bool tag = true;
        while (tag) {
            for (i = 1; i < k; i++) {
                ListNode* tmp = p3->next;
                p3->next = p2;
                p2 = p3;
                p3 = tmp;

                if (q2 != nullptr && q2->next != nullptr) {
                    q2 = q2->next;
                } else {
                    tag = false;
                }
            }

            if (tag) {
                p1->next = q2;
                p1 = q1;
                p2 = q1;
                p3 = q1->next;
                q1 = q2->next;
                q2 = q1;
            } else {
                p1 ->next = q1;
            }
        }

        return res;
    }
};