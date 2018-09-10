#include <iostream>
#include <vector>

class Solution {
public:
    bool searchMatrix(std::vector<std::vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0)
            return false;
        auto m = int(matrix.size()), n = int(matrix[0].size());
        for (int i = 0; i < m; i++) {
            if (target >= matrix[i][0] && target <= matrix[i][n - 1]) {
                for (int j = 0; j < n; j++) {
                    if (matrix[i][j] == target)
                        return true;
                }
            }
        }
        return false;
    }
};