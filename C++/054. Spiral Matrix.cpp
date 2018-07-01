#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return ans;
        int left = 0, right = int(matrix[0].size()) - 1;
        int top = 1, bottom = int(matrix.size()) - 1;
        int i = 0, j = 0, k = 0;
        bool tag = true;
        while (tag) {
            //right
            if (k % 4 == 0) {
                for (; j < right; j++)
                    ans.push_back(matrix[i][j]);
                right--;
                if (i == bottom) {
                    ans.push_back(matrix[i][j]);
                    tag = false;
                }
            }
            //down
            else if (k % 4 == 1) {
                for (; i < bottom; i++)
                    ans.push_back(matrix[i][j]);
                bottom--;
                if (j == left) {
                    ans.push_back(matrix[i][j]);
                    tag = false;
                }
            }
            //left
            else if (k % 4 == 2) {
                for (; j > left; j--)
                    ans.push_back(matrix[i][j]);
                left++;
                if (i == top) {
                    ans.push_back(matrix[i][j]);
                    tag = false;
                }
            }
            //up
            else {
                for (; i > top; i--)
                    ans.push_back(matrix[i][j]);
                top++;
                if (j == right) {
                    ans.push_back(matrix[i][j]);
                    tag = false;
                }
            }
            k++;
        }
        return ans;
    }
};

int main () {
    vector<vector<int>> matrix {
            {1,2,3},
            {2,2,3},
            {3,4,5},
            {1,2,3},
            {2,2,2},
    };
    Solution so;
    vector<int> ans = so.spiralOrder(matrix);
    for (auto i : ans)
        cout << i << " ";
    return 0;
}