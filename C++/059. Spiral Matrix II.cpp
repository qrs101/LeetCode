#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> generateMatrix(int n) {
        std::vector<std::vector<int>> res (n, std::vector<int>(n, 0));
        int num = 1;
        for (int left_top = 0, right_bottom = n - 1; left_top <= right_bottom; left_top++, right_bottom--) {
            if (left_top == right_bottom) {
                res[left_top][left_top] = num;
                break;
            }
            for (int i = left_top; i < right_bottom; num++, i++)
                res[left_top][i] = num;
            for (int i = left_top; i < right_bottom; num++, i++)
                res[i][right_bottom] = num;
            for (int i = right_bottom; i > left_top; num++, i--)
                res[right_bottom][i] = num;
            for (int i = right_bottom; i > left_top; num++, i--)
                res[i][left_top] = num;
        }
        return res;
    }
};