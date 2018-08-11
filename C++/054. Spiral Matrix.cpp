#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> spiralOrder(std::vector<std::vector<int>>& matrix) {
        std::vector<int> res;
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return res;
        int row = int(matrix.size()), col = int(matrix[0].size());
        std::vector<std::vector<bool>> seen(row, std::vector<bool>(col, false));
        std::vector<int> add_row{0, 1, 0, -1}, add_col{1, 0, -1, 0};
        int i = 0, j = 0, add = 0;
        for (int k = 0; k < row * col; k++) {
            res.emplace_back(matrix[i][j]);
            seen[i][j] = true;
            int next_i = i + add_row[add], next_j = j + add_col[add];
            bool condition1 = 0 <= next_i && next_i < row;
            bool condition2 = 0 <= next_j && next_j < col;
            if (condition1 && condition2 && !seen[next_i][next_j]) {
                i = next_i;
                j = next_j;
            } else {
                add = (add + 1) % 4;
                i = i + add_row[add];
                j = j + add_col[add];
            }
        }
        return res;
    }
};