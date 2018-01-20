#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int i, i_, j, j_;
        bool tag;
        i = i_ = 0;
        j = j_ = n - 1;

        if (height[0] <= height[n-1])
            tag = true;
        else
            tag = false;
        while (j_ - i_ > 1) {
            int container = (j - i) * min(height[i], height[j]);
            if (tag == true) {
                i_++;
                if (height[i_] <= height[i]) {
                    continue;
                } else if (height[i_] > height[i] && height[i_] <= height[j_]) {
                    int tmp = (j_ - i_) * height[i_];
                    if (tmp > container) {
                        i = i_;
                        j = j_;
                    }
                } else {
                    int tmp = (j_ - i_) * height[j_];
                    if (tmp > container) {
                        i = i_;
                        j = j_;
                    }
                    tag = false;
                }
            } else {
                j_--;
                if (height[j_] <= height[j]) {
                    continue;
                } else if (height[j_] > height[j] && height[j_] <= height[i_]) {
                    int tmp = (j_ - i_) * height[j_];
                    if (tmp > container) {
                        i = i_;
                        j = j_;
                    }
                } else {
                    int tmp = (j_ - i_) * height[i_];
                    if (tmp > container) {
                        i = i_;
                        j = j_;
                    }
                    tag = true;
                }
            }
        }

        return (j - i) * min(height[i], height[j]);
    }
};

int main() {
    Solution so;
    vector<int> a {2,3,4,5,18,17,6};
    int res = so.maxArea(a);
    cout << res << endl;
}