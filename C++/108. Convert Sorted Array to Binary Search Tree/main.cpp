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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int n = int(nums.size());
        if (n == 0)
            return nullptr;
        int a = n / 2;
        TreeNode* ans = new TreeNode(nums[a]);
        vector<int> left (nums.begin(), nums.begin() + a);
        vector<int> right(nums.begin() + a + 1, nums.end());
        ans->left = sortedArrayToBST(left);
        ans->right = sortedArrayToBST(right);
        return ans;
    }
};