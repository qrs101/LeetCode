#include <iostream>
#include <vector>

class Solution {
public:
    int maxArea(std::vector<int>& height) {
        int i = 0, j = int(height.size()) - 1;
        int res = 0;
        while (i < j) {
            int tmp = std::min(height[i], height[j]) * (j - i);
            res = std::max(res, tmp);
            if (height[i] <= height[j])
                i++;
            else
                j--;
        }
        return res;
    }
};