#include <iostream>
#include <vector>

class Solution {
public:
    int largestRectangleArea(std::vector<int>& heights) {
        auto n = int(heights.size());
        std::vector<int> L(unsigned(n) + 2, 0);
        std::vector<int> R(unsigned(n) + 2, 0);
        heights.insert(heights.begin(), 0);
        heights.emplace_back(0);
        for (int i = 1, j; i <= n; i++) {
            for (j = i; heights[j - 1] > heights[i]; j = L[j - 1]);
            if (heights[j - 1] < heights[i])
                L[i] = j;
            else
                L[i] = L[j - 1];
        }
        for (int i = n, j; i >= 1; i--) {
            for (j = i; heights[j + 1] > heights[i]; j = R[j + 1]);
            if (heights[j + 1] < heights[i])
                R[i] = j;
            else
                R[i] = R[j + 1];
        }
        int res = 0;
        for (int i = 1; i <= n; i++) {
            res = std::max(res, (R[i] - L[i] + 1) * heights[i]);
        }
        return res;
    }
};