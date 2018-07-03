#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if (root == nullptr)
            return res;
        vector<queue<TreeNode*>> q (2);
        q[0].push(root);
        int i = 0;
        while (!q[0].empty() || !q[1].empty()) {
            TreeNode *p;
            while (!q[i].empty()) {
                p = q[i].front();
                q[i].pop();
                if (p->left != nullptr)
                    q[1 - i].push(p->left);
                if (p->right != nullptr)
                    q[1 - i].push(p->right);
            }
            if (p)
                res.push_back(p->val);
            i = 1 - i;
        }
        return res;
    }
};