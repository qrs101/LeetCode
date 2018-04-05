#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == nullptr)
            return nullptr;
        if (head->next == nullptr)
            return new TreeNode(head->val);
        ListNode* p = head;
        int n, a;
        for (n = 0; p != nullptr; n++, p = p->next);
        for (p = head, a = n / 2 - 1; a > 0; p = p->next, a--);
        ListNode* q = p->next;
        p->next = nullptr;
        TreeNode* ans = new TreeNode(q->val);
        ans->left = sortedListToBST(head);
        ans->right = sortedListToBST(q->next);
        return ans;
    }
};