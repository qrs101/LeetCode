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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        if (root == nullptr)
            return ans;
        if (root->left == nullptr && root->right == nullptr) {
            ans.push_back(to_string(root->val));
            return ans;
        }
        vector<string> L = binaryTreePaths(root->left);
        vector<string> R = binaryTreePaths(root->right);
        string s = to_string(root->val) + "->";
        for (auto i : L)
            ans.push_back(s + i);
        for (auto i : R)
            ans.push_back(s + i);
        return ans;
    }
};