#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1)
            return s;
        int len = s.length();
        string res[numRows];
        string ans;
        bool tag = true;
        int n = 0;
        for (int i = 0; i < len; i++) {
            res[n] = res[n] + s[i];
            if (tag == true) {
                n++;
                if (n == numRows-1)
                    tag = false;
            } else {
                n--;
                if (n == 0)
                    tag = true;
            }
        }
        for (int i = 0; i < numRows; i++)
            ans = ans + res[i];
        return ans;
    }
};

int main() {
    Solution so;
    string ans = so.convert("AB", 1);
    cout << ans << endl;
}