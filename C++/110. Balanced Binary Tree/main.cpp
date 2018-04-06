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
    bool isBalanced(TreeNode* root) {
        if (helper(root) == -1)
            return false;
        return true;
    }

    int helper(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int left = helper(root->left);
        if (left == -1)
            return -1;
        int right = helper(root->right);
        if (right == -1)
            return -1;
        if (abs(left - right) <= 1)
            return max(left, right) + 1;
        return -1;
    }
};