#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if (divisor == 0 || (dividend == INT_MIN && divisor == -1))
            return INT_MAX;
        bool positive;
        if (dividend > 0 && divisor < 0 || dividend < 0 && divisor > 0)
            positive = false;
        else
            positive = true;
        long long a = labs(dividend);
        long long b = labs(divisor);
        int res = 0;
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
        return positive ? res : -res;
    }
};

int main() {
    Solution so;
    int res = so.divide(INT_MIN, 1);
    cout << res << endl;
    return 0;
}