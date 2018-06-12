#include<iostream>
#include<stack>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void reorderList(ListNode* head) {
        if (head == nullptr)
            return;
        stack<ListNode*> S;
        ListNode *p;
        int i;
        for (p = head, i = 0; p != nullptr; p = p->next, i++)
            S.push(p);
        for (p = head; !S.empty() && p != S.top() && p->next != S.top(); p = p->next->next) {
            S.top()->next = p->next;
            p->next = S.top();
            S.pop();
        }
        S.top()->next = nullptr;
    }
};

