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
    int minDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        if (root->left == nullptr && root->right == nullptr)
            return 1;
        else if (root->left != nullptr && root->right == nullptr)
            return minDepth(root->left) + 1;
        else if (root->left == nullptr && root->right != nullptr)
            return minDepth(root->right) + 1;
        else {
            int left = minDepth(root->left);
            int right = minDepth(root->right);
            return min(left, right) + 1;
        }
    }
};