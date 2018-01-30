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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector<ListNode*> v (lists);
        int n = v.size();
        if (n == 0)
            return nullptr;
        while (v.size() > 1) {
            if (n <= 1)
                n = v.size();
            ListNode* tmp = merge2Lists(v[0], v[1]);
            v.push_back(tmp);
            v.erase(v.begin(), v.begin() + 2);
            n = n - 2;
        }
        return v[0];
    }

    ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
        if (l1 == nullptr)
            return l2;
        if (l2 == nullptr)
            return l1;

        ListNode* p1 = l1;
        ListNode* p2 = l2;
        ListNode* p, * head;
        if (p1->val < p2->val) {
            head = p = p1;
            p1 = p1->next;
        } else {
            head = p = p2;
            p2 = p2->next;
        }
        while (p1 != nullptr && p2 != nullptr) {
            if (p1->val < p2->val) {
                p->next = p1;
                p1 = p1->next;
                p = p->next;
            } else {
                p->next = p2;
                p2 = p2->next;
                p = p->next;
            }
        }
        p1 == nullptr ? p->next = p2 : p->next = p1;
        return head;
    }
};