#include<iostream>
using namespace std;

class Solution {
public:
    int hammingWeight(uint32_t n) {
        int res = 0;
        for (int i = 0; i < 32; i++) {
            if ((n & 1) == 1)
                res++;
            n >>= 1;
        }
        return res;
    }
};

int main() {
    uint32_t n = 11;
    Solution so;
    int res = so.hammingWeight(128);
    cout << res << endl;
}