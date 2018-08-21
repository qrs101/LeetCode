#include <iostream>

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1)
            return x;
        long i = 1, j = x / 2 + 1;
        while (i < j - 1) {
            long m = (i + j) / 2;
            long tmp = m * m;
            if (tmp == x)
                return int(m);
            else if (tmp > x)
                j = m;
            else
                i = m;
        }
        return int(i);
    }
};