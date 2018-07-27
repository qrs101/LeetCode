#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *res = new ListNode(0), *first = res;
        first->next = head;
        while (true) {
            ListNode *last = first;
            for (int i = 0; i < k && last != nullptr; i++)
                last = last->next;
            if (last == nullptr)
                break;
            last = first->next;
            for (int i = 1; i < k; i++) {
                ListNode *tmp = last->next;
                last->next = last->next->next;
                tmp->next = first->next;
                first->next = tmp;
            }
            first = last;
        }
        return res->next;
    }
};