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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = int(preorder.size());
        if (n == 0)
            return nullptr;
        int i;
        for (i = 0; i < n && inorder[i] != preorder[0]; i++);
        vector<int> left_preorder (preorder.begin() + 1, preorder.begin() + i + 1);
        vector<int> left_inorder (inorder.begin(), inorder.begin() + i);
        TreeNode* left = buildTree(left_preorder, left_inorder);
        vector<int> right_preorder (preorder.begin() + i + 1, preorder.end());
        vector<int> right_inorder (inorder.begin() + i + 1, inorder.end());
        TreeNode* right = buildTree(right_preorder, right_inorder);
        TreeNode* root = new TreeNode(preorder[0]);
        root->left = left;
        root->right = right;
        return root;
    }
};