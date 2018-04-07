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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> ans;
        if (root == nullptr)
            return ans;
        if (root->left == nullptr && root->right == nullptr) {
            if (sum == root->val) {
                vector<int> tmp {sum};
                ans.push_back(tmp);
            }
            return ans;
        } else if (root->left != nullptr && root->right == nullptr) {
            vector<vector<int>> tmp = pathSum(root->left, sum - root->val);
            for (auto& i : tmp) {
                i.insert(i.begin(), root->val);
                ans.push_back(i);
            }
            return ans;
        } else if (root->left == nullptr && root->right != nullptr) {
            vector<vector<int>> tmp = pathSum(root->right, sum - root->val);
            for (auto& i : tmp) {
                i.insert(i.begin(), root->val);
                ans.push_back(i);
            }
            return ans;
        } else {
            vector<vector<int>> tmp1 = pathSum(root->left, sum - root->val);
            for (auto& i : tmp1) {
                i.insert(i.begin(), root->val);
                ans.push_back(i);
            }
            vector<vector<int>> tmp2 = pathSum(root->right, sum - root->val);
            for (auto& i : tmp2) {
                i.insert(i.begin(), root->val);
                ans.push_back(i);
            }
            return ans;
        }
    }
};