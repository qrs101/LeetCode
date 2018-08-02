#include <iostream>
#include <vector>

class Solution {
public:
    std::string multiply(std::string num1, std::string num2) {
        int size1 = int(num1.size()), size2 = int(num2.size());;
        std::vector<int> product (size1 + size2, 0);
        for (int i = size1 - 1; i >= 0; i--)
            for (int j = size2 - 1; j >= 0; j--)
                product[size1 + size2 - i - j - 2] += int(num1[i] - '0') * int(num2[j] - '0');

        int carry = 0;
        std::string res{""};
        for (int i = 0; i < size1 + size2; i++) {
            carry = product[i] + carry;
            res = char(carry % 10 + '0') + res;
            carry = carry / 10;
        }
        for (carry = 0; carry < int(res.size()) - 1 && res[carry] == '0'; carry++);
        return res.erase(0, carry);
    }
};