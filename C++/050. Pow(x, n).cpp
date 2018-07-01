#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (isinf(x))
            return 0;
        if (n == 0 && x != 0)
            return 1;
        else if (x == 0)
            return 0;
        double ans;
        if (n < 0) {
            x = 1 / x;
            n = -n;
        }
        if (n % 2 == 1)
            ans = x;
        else
            ans = 1;
        ans = ans * this->myPow(x * x, n / 2);
        return ans;
    }
};

int main() {
    Solution so;
    double ans = so.myPow(2, -2147483648);
    cout << ans << endl;
    return 0;
}