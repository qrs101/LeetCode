#include <iostream>
#include <stack>
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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> s;
        TreeNode* p = root;
        while (!s.empty() || p != nullptr) {
            while (p != nullptr) {
                s.push(p);
                p = p->left;
            }
            p = s.top();
            s.pop();
            ans.push_back(p->val);
            p = p->right;
        }
        return ans;
    }
};

int main() {
    stack<int> s;
    int i = s.top();
    cout << i << endl;
}