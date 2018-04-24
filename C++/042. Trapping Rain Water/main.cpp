#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        auto n = int(height.size());
        if (n < 3)
            return 0;
        vector<int> left (n, height[0]);
        vector<int> right(n, height[n - 1]);
        for (int i = 1; i < n; i++)
            left[i] = max(height[i], left[i - 1]);
        for (int i = n - 2; i >= 0; i--)
            right[i] = max(height[i], right[i + 1]);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += min(left[i], right[i]) - height[i];
        }
        return ans;
    }
};