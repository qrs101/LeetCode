#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if (n <= 0)
            return vector<vector<int>>();
        vector<vector<int>> ans (n, vector<int>(n, 1));
        int left_top = 0, right_bottom = n - 1;
        int num = 1;
        while (left_top <= right_bottom) {
            if (left_top == right_bottom) {
                ans[left_top][left_top] = num;
                break;
            }
            for (int i = left_top; i < right_bottom; num++, i++)
                ans[left_top][i] = num;
            for (int i = left_top; i < right_bottom; num++, i++)
                ans[i][right_bottom] = num;
            for (int i = right_bottom; i > left_top; num++, i--)
                ans[right_bottom][i] = num;
            for (int i = right_bottom; i > left_top; num++, i--)
                ans[i][left_top] = num;
            left_top++;
            right_bottom--;
        }
        return ans;
    }
};