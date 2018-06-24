#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ans = 0;
        int n = int(heights.size());
        heights.insert(heights.begin(), -1);
        heights.push_back(-1);
        vector<int> left(n + 1, 0);
        vector<int> right(n + 1, n + 1);
        for (int i = 2; i <= n; i++) {
            int j = i - 1;
            while (heights[j] != 0 && heights[j] > heights[i])
                j = left[j];
            if (heights[j] < heights[i])
                left[i] = j;
            else
                left[i] = left[j];
        }
        for (int i = n - 1; i >= 1; i--) {
            int j = i + 1;
            while (heights[j] != n + 1 && heights[j] > heights[i])
                j = right[j];
            if (heights[j] < heights[i])
                right[i] = j;
            else
                right[i] = right[j];
        }
        for (int i = 1; i <= n; i++) {
            int area = heights[i] * (right[i] - left[i] - 1);
            if (ans < area)
                ans = area;
        }
        return ans;
    }
};