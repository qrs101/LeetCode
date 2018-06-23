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
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0)
            return vector<TreeNode*>();
        vector<int> nums;
        for (int i = 1; i <= n; nums.push_back(i), i++);
        return helper(nums);
    }

    vector<TreeNode*> helper(vector<int> nums) {
        vector<TreeNode*> ans;
        if (nums.size() == 0) {
            ans.push_back(nullptr);
            return ans;
        }
        for (int i = 0; i < nums.size(); i++) {
            vector<int> p_nums(nums.begin(), nums.begin() + i);
            vector<int> a_nums(nums.begin() + i + 1, nums.end());
            vector<TreeNode*> p_node = helper(p_nums);
            vector<TreeNode*> a_node = helper(a_nums);
            for (auto& left : p_node) {
                for (auto& right : a_node) {
                    TreeNode* root = new TreeNode(nums[i]);
                    root->left = left;
                    root->right = right;
                    ans.push_back(root);
                }
            }
        }
        return ans;
    }
};

int main() {
    //Solution so;
    //vector<TreeNode*> ans = so.generateTrees(3);
    vector<int> n {1,2,3};
    vector<int> a(n.begin(), n.begin());
    vector<int> b(n.begin() + 1, n.end());
    cout << a.size() <<endl;
    cout << b.size() <<endl;
    return 0;
}