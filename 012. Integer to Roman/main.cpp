#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        vector<vector<string>> bit {
                {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
                {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
                {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
                {"", "M", "MM", "MMM"}
        };
        string ans = "";
        int tmp = num;
        for (int i = 1000, j = 3; j >= 0; i = i / 10, j--) {
            ans = ans + bit[j][tmp/i];
            tmp = tmp % i;
        }
        return ans;
    }
};

int main() {
    Solution so;
    string ans = so.intToRoman(3999);
    cout << ans << endl;
}