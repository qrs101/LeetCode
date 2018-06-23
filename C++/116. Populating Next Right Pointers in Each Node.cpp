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
        while (cur->left != nullptr) {
            TreeLinkNode* p = cur;
            while (p != nullptr) {
                p->left->next = p->right;
                if (p->next != nullptr)
                    p->right->next = p->next->left;
                p = p->next;
            }
            cur = cur->left;
        }
    }

    /*递归求解原问题
    void connect(TreeLinkNode* root) {
        if (root == nullptr)
            return;
        TreeLinkNode* p = root->left;
        TreeLinkNode* q = root->right;
        while (p != nullptr) {
            p->next = q;
            p = p->right;
            q = q->left;
        }
        connect(root->left);
        connect(root->right);
    }
    */
};