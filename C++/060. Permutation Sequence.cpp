#include <iostream>
#include <vector>

class Solution {
public:
    std::string getPermutation(int n, int k) {
        std::vector<int> num(n + 1, 1), offset(n + 1, 1);
        for (int i = 1; i <= n; i++) {
            num[i] = i;
            offset[i] = offset[i - 1] * i;
        }
        std::string res("");
        k = k - 1;
        for (int i = n; i > 0; k = k % offset[i - 1], i--) {
            int index = k / offset[i - 1] + 1;
            res += std::to_string(num[index]);
            num.erase(num.begin() + index);
        }
        return res;
    }
};