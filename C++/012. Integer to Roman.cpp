#include <iostream>
#include <vector>

class Solution {
public:
    std::string intToRoman(int num) {
        std::vector<std::vector<std::string>> bit {
                {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
                {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
                {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
                {"", "M", "MM", "MMM"}
        };
        std::string res = "";
        for (int i = 1000, k = 3; k >= 0; i = i / 10, k--) {
            res = res + bit[k][num / i];
            num = num % i;
        }
        return res;
    }
};