#include <iostream>
using namespace std;

struct TreeLinkNode {
    int val;
    TreeLinkNode *left, *right, *next;
    TreeLinkNode(int x) : val(x), left(NULL), right(NULL), next(NULL) {}
};

class Solution {
public:
    void connect(TreeLinkNode *root) {
        if (root == nullptr)
            return;
        TreeLinkNode* cur = root;
        while (true) {
            TreeLinkNode* p = cur;
            while (p != nullptr) {
                TreeLinkNode *a, *q;
                if (p->left == nullptr && p->right == nullptr) {
                    p = p->next;
                    continue;
                }
                else if (p->left != nullptr && p->right == nullptr)
                    a = p->left;
                else if (p->left == nullptr && p->right != nullptr)
                    a = p->right;
                else {
                    p->left->next = p->right;
                    a = p->right;
                }
                q = p->next;
                while (q != nullptr && q->left == nullptr && q->right == nullptr)
                    q = q->next;
                if (q == nullptr)
                    break;
                if (q->left != nullptr)
                    a->next = q->left;
                else
                    a->next = q->right;
                p = q;
            }
            while (cur != nullptr && cur->left == nullptr && cur->right == nullptr)
                cur = cur->next;
            if (cur == nullptr)
                break;
            if (cur->left != nullptr)
                cur = cur->left;
            else
                cur = cur->right;
        }
    }
};