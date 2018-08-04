#include <iostream>
#include <vector>

class Solution {
public:
    int trap(std::vector<int>& height) {
        auto n = int(height.size());
        std::vector<int> le_max(n, 0);
        std::vector<int> ri_max(n, 0);
        for (int i = 0, tmp_max = 0; i < n; i++) {
            tmp_max = std::max(height[i], tmp_max);
            le_max[i] = tmp_max;
        }
        for (int i = n - 1, tmp_max = 0; i >= 0; i--) {
            tmp_max = std::max(height[i], tmp_max);
            ri_max[i] = tmp_max;
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            res += std::min(le_max[i], ri_max[i]) - height[i];
        }
        return res;
    }
};