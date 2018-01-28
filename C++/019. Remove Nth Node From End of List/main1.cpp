#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        vector<ListNode*> L;
        ListNode* p = head;
        while (p != nullptr) {
            L.push_back(p);
            p = p->next;
        }
        if (n == L.size()) {
            ListNode* q = head->next;
            delete(head);
            return q;
        }
        p = L[L.size() - n - 1];
        ListNode* q = p->next;
        p->next = q->next;
        delete(q);
        return L[0];
    }
};