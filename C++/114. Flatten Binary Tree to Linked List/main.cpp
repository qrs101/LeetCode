#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == nullptr)
            return;
        TreeNode* T = helper(root);
    }

    TreeNode* helper(TreeNode* root) {
        TreeNode* T;
        if (root->left == nullptr) {
            if (root->right == nullptr)
                return root;
            T = helper(root->right);
            return T;
        }
        TreeNode* p = root->right;
        root->right = root->left;
        root->left = nullptr;
        T = helper(root->right);
        T->right = p;
        if (p != nullptr)
            T = helper(p);
        return T;
    }
};