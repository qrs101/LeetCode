#include <iostream>
#include <vector>

class Solution {
public:
    std::string addBinary(std::string a, std::string b) {
        std::string res("");
        int carry = 0;
        for (int i = int(a.size()) - 1, j = int(b.size()) - 1; i >= 0 || j >= 0; i--, j--) {
            int num1 = 0, num2 = 0;
            if (i >= 0) num1 = a[i] - '0';
            if (j >= 0) num2 = b[j] - '0';
            carry = carry + num1 + num2;
            res = std::to_string(carry & 1) + res;
            carry = carry >> 1;
        }
        if (carry == 1)
            res = '1' + res;
        return res;
    }
};