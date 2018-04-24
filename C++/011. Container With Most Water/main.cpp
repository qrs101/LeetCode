#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0, j = int(height.size()) - 1;
        int ans = 0;
        while (i < j) {
            int tmp = min(height[i], height[j]) * (j - i);
            ans = max(ans, tmp);
            if (height[i] <= height[j])
                i++;
            else
                j--;
        }
        return ans;
    }
};