#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (head == nullptr)
            return nullptr;
        ListNode *p1 = head;
        ListNode *p2 = head;
        while (p2 != nullptr) {
            if (p2->next == nullptr || p2->next->next == nullptr)
                return nullptr;
            p2 = p2->next->next;
            p1 = p1->next;
            if (p1 == p2)
                break;
        }
        int n = 0;
        do {
            p1 = p1->next;
            p2 = p2->next->next;
            n++;
        } while (p1 != p2);
        p1 = head;
        p2 = head;
        for (int i = 0; i < n; i++) {
            p2 = p2->next;
        }
        while (p1 != p2) {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;
    }
};