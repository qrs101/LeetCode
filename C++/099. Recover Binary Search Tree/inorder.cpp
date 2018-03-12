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
    void recoverTree(TreeNode* root) {
        vector<TreeNode*> in_array = inorder(root);
        TreeNode* p1, *p2;
        int n = int(in_array.size());
        for (int i = 0, num = 0; i < n - 1; i++) {
            if (in_array[i]->val > in_array[i + 1]->val && num == 0) {
                p1 = in_array[i];
                num++;
                if (i + 1 == n - 1 || in_array[i]->val < in_array[i + 2]->val) {
                    p2 = in_array[i + 1];
                    break;
                }
            } else if (in_array[i]->val > in_array[i + 1]->val && num == 1) {
                p2 = in_array[i + 1];
                break;
            }
        }
        int tmp = p1->val;
        p1->val = p2->val;
        p2->val = tmp;
    }

    vector<TreeNode*> inorder(TreeNode* root) {
        vector<TreeNode*> ans;
        if (root == nullptr)
            return ans;
        vector<TreeNode*> tmp1 = inorder(root->left);
        vector<TreeNode*> tmp2 = inorder(root->right);
        ans.insert(ans.end(), tmp1.begin(), tmp1.end());
        ans.push_back(root);
        ans.insert(ans.end(), tmp2.begin(), tmp2.end());
        return ans;
    }
};