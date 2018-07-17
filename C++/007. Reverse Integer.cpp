#include <iostream>
#include <climits>

class Solution {
public:
    int reverse(int x) {
        long res = 0;
        int symbol = 1;
        if (x < 0) {
            symbol = -1;
            x = -x;
        }
        while (x != 0) {
            int r = x % 10;
            x /= 10;
            res *= 10;
            res += r;
        }
        if (symbol * res > INT32_MAX || symbol * res < INT32_MIN)
            return 0;
        return int(symbol * res);
    }
};