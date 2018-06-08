#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle(ListNode *head) {
        ListNode *p = head;
        ListNode *q = head;
        if (head == nullptr)
            return false;
        while (q != nullptr) {
            if (q->next == nullptr || p->next->next == nullptr)
                return false;
            q = q->next->next;
            p = p->next;
            if (p == q)
                return true;
        }
        return false;
    }
};