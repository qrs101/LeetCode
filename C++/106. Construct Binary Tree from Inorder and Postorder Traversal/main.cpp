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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = int(postorder.size());
        if (n == 0)
            return nullptr;
        int i;
        for (i = 0; i < n && inorder[i] != postorder[n - 1]; i++);
        vector<int> left_postorder (postorder.begin(), postorder.begin() + i);
        vector<int> left_inorder (inorder.begin(), inorder.begin() + i);
        TreeNode* left = buildTree(left_inorder, left_postorder);
        vector<int> right_postorder (postorder.begin() + i, postorder.end() - 1);
        vector<int> right_inorder (inorder.begin() + i + 1, inorder.end());
        TreeNode* right = buildTree(right_inorder, right_postorder);
        TreeNode* root = new TreeNode(postorder[n - 1]);
        root->left = left;
        root->right = right;
        return root;
    }
};