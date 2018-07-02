#include<iostream>
#include<stdint.h>
using namespace std; 
    
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t res = 0;
        for (int i = 0; i < 32; i++) {
            uint32_t tmp = n & 1;
            n >>= 1;
            res <<= 1;
            res += tmp;
        }
        return res;
    }
};

int main() {
    Solution so;
    uint32_t res = so.reverseBits(43261596);
    cout << res << endl;
}