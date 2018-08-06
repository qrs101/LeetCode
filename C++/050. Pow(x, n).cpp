#include <iostream>
#include <cmath>

class Solution {
public:
    double myPow(double x, int n) {
        if (isinf(x) || x == 0)
            return 0;
        if (n == 0)
            return 1;
        double res;
        if (n < 0) {
            x = 1 / x;
            n = -n;
        }
        if (n % 2 == 1)
            res = x;
        else
            res = 1;
        res = res * this->myPow(x * x, n / 2);
        return res;
    }
};