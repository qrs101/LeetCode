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
    bool isSymmetric(TreeNode* root) {
        if (root == nullptr)
            return true;
        return helper(root->left, root->right);
    }

    bool helper(TreeNode* r1, TreeNode* r2) {
        if (r1 == nullptr && r2 == nullptr)
            return true;
        else if ((r1 != nullptr && r2 == nullptr) || (r1 == nullptr && r2 != nullptr))
            return false;
        else if (r1->val != r2->val)
            return false;
        else
            return helper(r1->left, r2->right) && helper(r1->right, r2->left);
    }
};