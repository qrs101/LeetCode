#include <iostream>
#include <vector>

class Solution {
public:
    int minimumTotal(std::vector<std::vector<int>>& triangle) {
        auto n = int(triangle.size());
        std::vector<int> res (triangle[n - 1].begin(), triangle[n - 1].end());
        for (int i = n - 1; i > 0; i--) {
            for (int j = 0; j < i; j++) {
                res[j] = std::min(res[j], res[j + 1]) + triangle[i - 1][j];
            }
        }
        return res[0];
    }
};