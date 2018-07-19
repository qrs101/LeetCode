#include <iostream>
#include <unordered_map>

class Solution {
public:
    int romanToInt(std::string s) {
        std::unordered_map<char, int> bit = {
            {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
        };

        int res = bit[s.back()];
        for (int i = int(s.size()) - 2; i >= 0; i--) {
            if (bit[s[i]] < bit[s[i + 1]]) {
                res = res - bit[s[i]];
            } else {
                res = res + bit[s[i]];
            }
        }
        return res;
    }
};