#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (int(matrix.size()) == 0 || int(matrix[0].size()) == 0)
            return 0;
        auto m = int(matrix.size());
        auto n = int(matrix[0].size());
        vector<int> heights (n, 0);
        for (int i = 0; i < n; i++)
            if (matrix[0][i] == '1')
                heights[i] = 1;
        int ans = largestRectangleArea(heights);
        for (int i = 1; i < m; i++) {
            for (int j = 0; j < n; j++)
                if (matrix[i][j] == '0')
                    heights[j] = 0;
                else
                    heights[j]++;
            int tmp = largestRectangleArea(heights);
            if (ans < tmp)
                ans = tmp;
        }
        return ans;
    }

    int largestRectangleArea(vector<int> heights) {
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


int main() {
    vector<vector<char>> matrix{
            {'1', '0', '1', '0', '0'},
            {'1', '0', '1', '1', '1'},
            {'1', '1', '1', '1', '1'},
            {'1', '0', '0', '1', '0'}
    };
    Solution so;
    int ans = so.maximalRectangle(matrix);
    cout << ans << endl;
    return 0;
}