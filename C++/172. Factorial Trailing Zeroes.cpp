#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        for (int i = n; i > 0; i = i / 5) {
            res += i / 5;
        }
        return res;
    }
};

int main() {
    Solution so;
    int res = so.trailingZeroes(1808548329);
    cout << res << endl;
}