#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        int len_A, len_B;
        ListNode *pA, *pB;

        for (len_A = 0, pA = headA; pA != nullptr; len_A++, pA = pA->next);
        for (len_B = 0, pB = headB; pB != nullptr; len_B++, pB = pB->next);

        pA = headA;
        pB = headB;
        if (len_A > len_B) {
            for (int i = len_A - len_B; i > 0; i--, pA = pA->next);
        } else {
            for (int i = len_B - len_A; i > 0; i--, pB = pB->next);
        }

        while (pA != nullptr) {
            if (pA == pB)
                return pA;
            pA = pA->next;
            pB = pB->next;
        }
        return nullptr;
    }
};