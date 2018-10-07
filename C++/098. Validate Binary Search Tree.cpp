#include <iostream>
#include <vector>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isValidBST(TreeNode* root) {
        vector<int> arr = inorder(root);
        for (int i = 1; i < int(arr.size()); i++) {
            if (arr[i - 1] >= arr[i])
                return false;
        }
        return true;
    }

    vector<int> inorder(TreeNode *root) {
        vector<int> res;
        if (root == nullptr)
            return res;
        res = inorder(root->left);
        res.emplace_back(root->val);
        vector<int> tmp = inorder(root->right);
        res.insert(res.end(), tmp.begin(), tmp.end());
        return res;
    }
};
