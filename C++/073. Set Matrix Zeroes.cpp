#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        set<int> row;
        set<int> column;
        auto m = int(matrix.size());
        auto n = int(matrix[0].size());
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++)
                if (matrix[i][j] == 0) {
                    row.insert(i);
                    column.insert(j);
                }
        }
        for (auto i : row) {
            for (int j = 0; j < n; j++)
                matrix[i][j] = 0;
        }
        for (auto j : column) {
            for (int i = 0; i < m; i++)
                matrix[i][j] = 0;
        }
    }
};