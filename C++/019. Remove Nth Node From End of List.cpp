#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *res = new ListNode(0);
        res->next = head;
        ListNode *front = res, *rear = res;
        int i;
        for (i = 0; i < n && rear->next != nullptr; i++) {
            rear = rear->next;
        }
        if (i < n) {
            return rear->next;
        }
        while (rear->next != nullptr) {
            front = front->next;
            rear = rear->next;
        }
        front->next = front->next->next;
        return res->next;
    }
};