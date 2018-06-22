#include <iostream>
#include <climits>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int ans = INT_MIN;
        helper(root, ans);
        return ans;
    }

    int helper(TreeNode* root, int& ans) {
        if (root == nullptr)
            return 0;
        int l = helper(root->left, ans);
        int r = helper(root->right, ans);
        if (l < 0)
            l = 0;
        if (r < 0)
            r = 0;
        ans = max(ans, root->val + l + r);
        return max(root->val + l, root->val + r);
    }
};