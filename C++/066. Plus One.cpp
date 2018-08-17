#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<int> plusOne(std::vector<int>& digits) {
        int carry = 1;
        for (int i = int(digits.size()) - 1; i >= 0; i--) {
            carry = digits[i] + carry;
            digits[i] = carry % 10;
            carry = carry / 10;
            if (carry == 0)
                break;
        }
        if (carry != 0)
            digits.insert(digits.begin(), carry);
        return digits;
    }
};