#include <iostream>
#include <vector>

class Solution {
public:
    std::string countAndSay(int n) {
        std::vector<std::string> res {"", "1"};
        for (int i = 2; i <= n; i++) {
            std::string str = res[i - 1];
            res.emplace_back("");
            int num = 1, j = 1;
            for (; j < str.size(); j++) {
                if (str[j] == str[j - 1])
                    num++;
                else {
                    res[i] += std::to_string(num) + str[j - 1];
                    num = 1;
                }
            }
            res[i] += std::to_string(num) + str[j - 1];
        }
        return res[n];
    }
};