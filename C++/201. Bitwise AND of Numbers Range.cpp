#include <iostream>
#include <climits>

class Solution {
public:
    int rangeBitwiseAnd(int m, int n) {
        int res = 0;
        int curNumber = 1, offset = 0;
        int range = n - m;
        for (int i = 0; i < 31; i++) {
            if ((curNumber & m) != 0) {
                if (offset < curNumber - range) {
                    res += curNumber;
                }
                offset += curNumber;
            }
            curNumber <<= 1;
        }
        return res;
    }
};