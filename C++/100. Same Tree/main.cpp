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
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if (p == nullptr && q == nullptr)
            return true;
        else if (p == nullptr && q!= nullptr || p != nullptr && q == nullptr)
            return false;
        else if (p->val != q->val)
            return false;
        bool a = isSameTree(p->left, q->left);
        if (!a)
            return false;
        bool b = isSameTree(p->right, q->right);
        if (!b)
            return false;
        return true;
    }

    vector<int> preorder(TreeNode* p) {
        vector<int> ans;
        if (p == nullptr)
            return ans;
        ans.push_back(p->val);
        vector<int> tmp1 = preorder(p->left);
        vector<int> tmp2 = preorder(p->right);
        ans.insert(ans.end(), tmp1.begin(), tmp1.end());
        ans.insert(ans.end(), tmp2.begin(), tmp2.end());


        vector<int> p_pre = preorder(p);
        vector<int> q_pre = preorder(q);
        if (p_pre.size() != q_pre.size())
            return false;
        for (int i = 0; i < int(p_pre.size()); i++)
            if (p_pre[i] != q_pre[i])
                return false;
        vector<int> p_in = inorder(p);
        vector<int> q_in = inorder(q);
        for (int i = 0; i < int(p_in.size()); i++)
            if (p_in[i] != q_in[i])
                return false;
        return true;


        return ans;
    }

    vector<int> inorder(TreeNode* p) {
        vector<int> ans;
        if (p == nullptr)
            return ans;
        vector<int> tmp1 = inorder(p->left);
        vector<int> tmp2 = inorder(p->right);
        ans.insert(ans.end(), tmp1.begin(), tmp1.end());
        ans.push_back(p->val);
        ans.insert(ans.end(), tmp2.begin(), tmp2.end());
        return ans;
    }
};