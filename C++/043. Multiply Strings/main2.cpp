#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        int size1 = num1.size();
        int size2 = num2.size();
        string ans = "";
        vector<int> product (size1 + size2, 0);
        for (int i = size1 - 1; i >= 0; i--) {
            for (int j = size2 - 1; j >= 0; j--) {
                int a = int(num1[i] - '0');
                int b = int(num2[j] - '0');
                int k = size1 + size2 - i - j - 2;
                product[k] += a * b;
            }
        }
        int carry = 0;
        for (int i = 0; i < size1 + size2; i++) {
            int p = product[i] + carry;
            carry = p / 10;
            p = p % 10;
            ans = char(p + '0') + ans;
        }
        int i;
        for (i = 0; ans[i] == '0' && i < ans.size() - 1; i++);
        ans = ans.erase(0, i);
        return ans;
    }
};

int main() {
    string s1 = "0";
    string s2 = "1341230";
    Solution so;
    string ans = so.multiply(s1, s2);
    cout << ans << endl;
    return 0;
}