#include <iostream>
#include <vector>

class Solution {
public:
    void rotate(std::vector<std::vector<int>>& matrix) {
        auto n = int(matrix.size()) - 1;
        for (int i = 0, j = n; i < j; i++, j--) {
            std::vector<int> tmp = matrix[i];
            matrix[i] = matrix[j];
            matrix[j] = tmp;
        }

        for (int i = 0; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }
    }
};