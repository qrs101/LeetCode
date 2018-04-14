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
    int sumNumbers(TreeNode* root) {
        vector<string> tmp = helper(root);
        int ans = 0;
        for (auto i : tmp)
            ans += stoi(i);
        return ans;
    }

    vector<string> helper(TreeNode* root) {
        vector<string> ans;
        if (root == nullptr)
            return ans;
        if (root->left == nullptr && root->right == nullptr) {
            ans.push_back(to_string(root->val));
            return ans;
        }
        vector<string> tmp1 = helper(root->left);
        vector<string> tmp2 = helper(root->right);
        if (tmp1.size() != 0) {
            for (auto& i : tmp1) {
                i = to_string(root->val) + i;
                ans.push_back(i);
            }
        }
        if (tmp2.size() != 0) {
            for (auto& i : tmp2) {
                i = to_string(root->val) + i;
                ans.push_back(i);
            }
        }
        return ans;
    }
};