#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        auto n = int(digits.size());
        int carry = 0;
        digits[n - 1]++;
        for (int i = n - 1; i >= 0; i--) {
            int tmp = digits[i] + carry;
            carry = tmp / 10;
            digits[i] = tmp % 10;
            if (carry == 0)
                break;
        }
        if (carry != 0)
            digits.insert(digits.begin(), carry);
        return digits;
    }
};