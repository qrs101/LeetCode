#include <iostream>
using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x == 0 || x == 1)
            return x;
        long a = 1, b = x;
        while (b - a > 1) {
            long m = (a + b) / 2;
            long tmp = m * m;
            if (tmp == x)
                return int(m);
            else if (tmp > x || tmp < 0)
                b = m;
            else
                a = m;
        }
        if (a * a > x)
            return int(a - 1);
        return int(a);
    }
};

int main() {
    Solution so;
    int x = so.mySqrt(2147395599);
    cout << x << endl;
    return 0;
}