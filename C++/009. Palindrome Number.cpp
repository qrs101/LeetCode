#include <iostream>

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0))
            return false;
        int y = 0;
        while (x > y) {
            y = y * 10;
            y = y + (x % 10);
            x = x / 10;
        }
        if (x == y || x == y / 10)
            return true;
        else
            return false;
    }
    /**
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        int y = 0;
        int tmp = x;
        while (tmp != 0) {
            y = y * 10;
            y = y + (tmp % 10);
            tmp = tmp / 10;
        }
        if (x == y)
            return true;
        else
            return false;
    }
    **/
};