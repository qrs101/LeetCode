#include <iostream>
using namespace std;

class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0")
            return "0";
        string ans = "";
        int size1 = int(num1.size());
        int size2 = int(num2.size());
        for (int i = size1 - 1, k = 0; i >= 0; i--, k++) {
            int cur_num1 = int(num1[i] - '0');
            int carry = 0;
            string tmp = "";
            if (cur_num1 == 0)
                continue;
            else if (cur_num1 == 1) {
                tmp = num2;
                tmp.append(k, '0');
                ans = add(ans, tmp);
                continue;
            }
            for (int j = size2 - 1; j >= 0; j--) {
                int cur_num2 = int(num2[j] - '0');
                int product = cur_num1 * cur_num2 + carry;
                carry = product / 10;
                product = product % 10;
                tmp = char(product + '0') + tmp;
            }
            if (carry != 0)
                tmp = char(carry + '0') + tmp;
            tmp.append(k, '0');
            ans = add(ans, tmp);
        }
        return ans;
    }

    string add(string ans, string tmp) {
        int size1 = ans.size();
        int size2 = tmp.size();
        int carry = 0;
        string str = "";
        for (int i = size1 - 1, j = size2 - 1; i >= 0 || j >= 0; i--, j--) {
            int num1, num2, sum;
            if (j < 0) {
                num1 = int(ans[i] - '0');
                sum = num1 + carry;
            } else if (i < 0) {
                num2 = int(tmp[j] - '0');
                sum = num2 + carry;
            } else {
                num1 = int(ans[i] - '0');
                num2 = int(tmp[j] - '0');
                sum = num1 + num2 + carry;
            }
            carry = sum / 10;
            sum = sum % 10;
            str = char(sum + '0') + str;
            if (carry == 0 && j < 0) {
                str = ans.substr(0, i) + str;
                break;
            } else if (carry == 0 && i < 0) {
                str = tmp.substr(0, j) + str;
                break;
            }
        }
        if (carry != 0)
            str = char(carry + '0') + str;
        return str;
    }
};

int main() {
    string s1 = "70";
    string s2 = "70";
    Solution so;
    s1 = so.add(s1, s2);
    cout << s1 << endl;
    return 0;
}