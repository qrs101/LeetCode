#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n = int(height.size());
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (i + 1 < n && height[i] <= height[i + 1])
                continue;
            int tmp = i + 1;
            int h, l = 0;
            bool tag = true;
            for (int j = i + 1; j < n; j++) {
                if (j + 1 < n && height[j + 1] > height[j])
                    tag = false;
                if (height[j] >= height[i]) {
                    h = height[i];
                    l = j - i - 1;
                    tmp = j;
                    break;
                } else if (height[j] > height[tmp]) {
                    h = height[j];
                    l = j - i - 1;
                    tmp = j;
                }
            }
            if (tag)
                break;
            else if (l == 0)
                continue;
            int C = 0;
            for (int k = i + 1; k < tmp; k++)
                C = C + height[k];
            ans = ans + (h * l - C);
            i = tmp - 1;
        }
        return ans;
    }
};

int main() {
    vector<int> height {2,1,0,2};
    Solution so;
    int ans = so.trap(height);
    cout << ans << endl;
    return 0;
}