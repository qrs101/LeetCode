#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if (k == 0 || head == nullptr || head->next == nullptr)
            return head;
        ListNode* a = head;
        ListNode* b = head;
        int length = 0;
        for (int i = 0; i < k && b!= nullptr; i++) {
            length++;
            b = b->next;
        }
        if (b == nullptr) {
            int t = k % length;
            if (t == 0)
                return head;
            b = head;
            for (int i = 0; i < t; i++)
                b = b->next;
        }
        while (b->next != nullptr) {
            a = a->next;
            b = b->next;
        }
        b = a->next;
        a->next = b->next;
        b->next = head;
        ListNode* ans = b;
        while (a->next != nullptr) {
            ListNode* p = a->next;
            a->next = p->next;
            p->next = b->next;
            b->next = p;
            b = p;
        }
        return ans;
    }
};