#include <iostream>
#include <vector>

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeKLists(std::vector<ListNode*>& lists) {
        if (lists.size() == 0)
            return nullptr;
        while (int(lists.size()) > 1) {
            lists.push_back(merge2Lists(lists[0], lists[1]));
            lists.erase(lists.begin(), lists.begin() + 2);
        }
        return lists[0];
    }

    ListNode* merge2Lists(ListNode* l1, ListNode* l2) {
        ListNode *res = new ListNode(0), *p = res;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                p->next = l1;
                l1 = l1->next;
            } else {
                p->next = l2;
                l2 = l2->next;
            }
            p = p->next;
        }
        if (l1 == nullptr)
            p->next = l2;
        else
            p->next = l1;
        return res->next;
    }
};