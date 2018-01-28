#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        if (x == -2147483648)
            return 0;
        const int overflow_bit = 10;
        vector<int> overflow_num {2,1,4,7,4,8,3,6,4,7};
        vector<int> res;
        bool positive;
        int num, ans = 0;
        if (x > 0) {
            positive = true;
            num = x;
        } else {
            positive = false;
            overflow_num[9] = 8;
            num = -x;
        }

        int i = 0;
        while (num != 0) {
            int remainder = num % 10;
            num = num / 10;
            res.insert(res.begin(), remainder);
            i++;
        }

        if (i == 10) {
            for (int j = 0; j < 10; j++) {
                if (res[9-j] > overflow_num[j])
                    return 0;
                else if (res[9-j] < overflow_num[j])
                    break;
            }
        }

        int a = 1;
        for (vector<int>::iterator i = res.begin(); i != res.end(); i++, a = a*10) {
            ans = ans + (*i) * a;
        }
        if (positive)
            return ans;
        else
            return -ans;
    }
};

int main() {
    Solution so;
    int res = so.reverse(-2147483648);
    cout << res << endl;
}