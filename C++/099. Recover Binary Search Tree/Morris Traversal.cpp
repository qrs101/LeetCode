#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode *p1 = nullptr, *p2 = nullptr, *t1 = nullptr, *t2 = nullptr;
        TreeNode *cur = root;
        bool tag = true;
        while (cur != nullptr) {
            if (cur->left == nullptr) {
                t1 = t2;
                t2 = cur;
                cur = cur->right;
            } else {
                TreeNode *q = cur->left;
                while (q->right != nullptr && q->right != cur)
                    q = q->right;
                if (q->right == nullptr) {
                    q->right = cur;
                    cur = cur->left;
                } else if (q->right == cur) {
                    q->right = nullptr;
                    t1 = t2;
                    t2 = cur;
                    cur = cur->right;
                }
            }
            if (t1 != nullptr && t2 != nullptr) {
                if (tag && t1->val > t2->val) {
                    p1 = t1;
                    p2 = t2;
                    tag = false;
                } else if (t1->val > t2->val) {
                    p2 = t2;
                }
            }
        }
        if (p1 != nullptr && p2 != nullptr) {
            int tmp = p1->val;
            p1->val = p2->val;
            p2->val = tmp;
        }
    }
};

void inorder(TreeNode *root) {
    if (root == nullptr)
        return;
    inorder(root->left);
    cout << root->val << " ";
    inorder(root->right);
}

int main() {
    TreeNode* root = new TreeNode(4);
    root->left = new TreeNode(3);
    root->left->right = new TreeNode(2);
    root->left->right->right = new TreeNode(1);
    inorder(root);
    cout << endl;
    Solution so;
    so.recoverTree(root);
    inorder(root);
    cout << endl;
    return 0;
}