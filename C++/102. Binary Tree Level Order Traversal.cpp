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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr)
            return ans;
        vector<queue<TreeNode*>> Q(2);
        Q[0].push(root);
        int i = 0;
        while (!Q[0].empty() || !Q[1].empty()) {
            vector<int> tmp;
            while (!Q[i].empty()) {
                TreeNode* p = Q[i].front();
                tmp.push_back(p->val);
                if (p->left != nullptr)
                    Q[1 - i].push(p->left);
                if (p->right != nullptr)
                    Q[1 - i].push(p->right);
                Q[i].pop();
            }
            ans.push_back(tmp);
            i = 1 - i;
        }
        return ans;
    }
};