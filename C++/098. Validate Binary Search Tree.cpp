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
    bool isValidBST(TreeNode* root) {
        vector<int> inorder_array = inorder(root);
        for (int i = 0; i < int(inorder_array.size()) - 1; i++)
            if (inorder_array[i] >= inorder_array[i + 1])
                return false;
        return true;
    }

    vector<int> inorder(TreeNode* root) {
        vector<int> ans;
        if (root == nullptr)
            return ans;
        ans = inorder(root->left);
        ans.push_back(root->val);
        vector<int> tmp = inorder(root->right);
        ans.insert(ans.end(), tmp.begin(), tmp.end());
        return ans;
    }
};

int main() {
    TreeNode* root = nullptr;
    Solution so;
    bool ans = so.isValidBST(root);
    cout << ans << endl;
    return 0;
}