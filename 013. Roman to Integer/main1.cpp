#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        vector<vector<string>> bit {
                {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"},
                {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
                {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
                {"", "M", "MM", "MMM"}
        };
        int len = s.length();
        int k = 0;
        int ans = 0;
        for (int i = 0, j = 1000; i < len + 1; i++) {
            if (j == 1000) {
                if (s[k] == 'M') {
                    if (s[i] != 'M' || i == len) {
                        ans = ans + (i - k) * j;
                        j = 100;
                        k = i;
                        i--;
                    }
                } else {
                    j = 100;
                    i--;
                }
            } else if (j == 100) {
                if (s[k] == 'C' || s[k] == 'D') {
                    if ((s[i] != 'C' && s[i] != 'D' && s[i] != 'M') || i == len) {
                        string tmp = s.substr(k, i-k);
                        int t;
                        for (t = 0; t < 10; t++) {
                            if (tmp == bit[2][t])
                                break;
                        }
                        ans = ans + t * j;
                        j = 10;
                        k = i;
                        i--;
                    }
                } else {
                    j = 10;
                    i--;
                }
            } else if (j == 10) {
                if (s[k] == 'X' || s[k] == 'L') {
                    if ((s[i] != 'X' && s[i] != 'L' && s[i] != 'C') || i == len) {
                        string tmp = s.substr(k, i-k);
                        int t;
                        for (t = 0; t < 10; t++) {
                            if (tmp == bit[1][t])
                                break;
                        }
                        ans = ans + t * j;
                        j = 1;
                        k = i;
                        i--;
                    }
                } else {
                    j = 1;
                    i--;
                }
            } else if (j == 1){
                string tmp = s.substr(k);
                int t;
                for (t = 0; t < 10; t++){
                    if (tmp == bit[0][t])
                        break;
                }
                ans = ans + t * j;
                break;
            }
        }

        return ans;
    }
};

int main() {
    Solution so;
    int ans = so.romanToInt("MMIII");
    cout << ans << endl;
}