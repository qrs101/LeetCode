#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0 || matrix[0].size() == 0 || target < matrix[0][0])
            return false;
        for (int i = 1; i < int(matrix.size()); i++) {
            if (target >= matrix[i][0])
                continue;
            for (int j = 0; j < int(matrix[i - 1].size()); j++) {
                if (matrix[i - 1][j] == target)
                    return true;
            }
            return false;
        }
        for (auto i = int(matrix.size()) - 1, j = 0; j < matrix[i].size(); j++)
            if (matrix[i][j] == target)
                return true;
        return false;
    }
};