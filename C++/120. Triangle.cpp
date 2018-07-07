#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        auto n = int(triangle.size());
        vector<int> res (triangle[n - 1].begin(), triangle[n - 1].end());
        for (int i = n - 1; i > 0; i--) {
            for (int j = 0; j < i; j++) {
                res[j] = min(res[j], res[j + 1]) + triangle[i - 1][j];
            }
        }
        return res[0];
    }
};