#include <iostream>
#include <climits>

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        int res = 0, symbol = 1;
        if (dividend > 0 && divisor < 0 || dividend < 0 && divisor > 0)
            symbol = -1;
        long a = labs(dividend), b = labs(divisor);
        while (a >= b) {
            long tmp = b;
            int r = 1;
            while (a > (tmp << 1)) {
                tmp <<= 1;
                r <<= 1;
            }
            a = a - tmp;
            res = res + r;
        }
        return symbol * res;
    }
};