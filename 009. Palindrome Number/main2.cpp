#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0))
            return false;
        int tmp = x;
        int ans = 0;
        while (ans < tmp) {
            ans = ans * 10;
            ans = ans + (tmp % 10);
            tmp = tmp / 10;
        }
        if (ans == tmp || ans / 10 == tmp)
            return true;
        else
            return false;
    }
};

int main() {
    Solution so;
    bool b = so.isPalindrome(1000000000);
    cout << b << endl;
}