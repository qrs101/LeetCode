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
        helper(root);
    }

    void helper(TreeLinkNode* root) {
        if (root == nullptr)
            return;
        TreeLinkNode* p = root->left;
        TreeLinkNode* q = root->right;
        while (p != nullptr) {
            p->next = q;
            p = p->right;
            q = q->left;
        }
        helper(root->left);
        helper(root->right);
    }
};