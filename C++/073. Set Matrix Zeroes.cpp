#include <iostream>
#include <vector>

class Solution {
public:
    void setZeroes(std::vector<std::vector<int>>& matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return;
        int m = int(matrix.size()), n = int(matrix[0].size());
        bool col_zero = false, row_zero = false;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    if (i == 0)
                        row_zero = true;
                    else
                        matrix[i][0] = 0;
                    if (j == 0)
                        col_zero = true;
                    else
                        matrix[0][j] = 0;
                }
            }
        }
        for (int i = 1; i < m; i++) {
            if (matrix[i][0] == 0) {
                for (int j = 0; j < n; matrix[i][j] = 0, j++);
            }
        }
        for (int j = 1; j < n; j++) {
            if (matrix[0][j] == 0) {
                for (int i = 0; i < m; matrix[i][j] = 0, i++);
            }
        }
        if (row_zero)
            for (int j = 0; j < n; matrix[0][j] = 0, j++);
        if (col_zero)
            for (int i = 0; i < m; matrix[i][0] = 0, i++);
    }
};