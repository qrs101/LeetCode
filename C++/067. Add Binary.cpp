#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string str1, str2;
        if (a.size() > b.size()) {
            str1 = a;
            str2 = b;
        } else {
            str1 = b;
            str2 = a;
        }
        auto m = int(str1.size());
        auto n = int(str2.size());
        char carry = '0';
        for (int i = m - 1, j = n - 1; i >= 0; i--, j--) {
            char c = '0';
            if (j >= 0)
                c = str2[j];
            string tmp = add(str1[i], c, carry);
            str1[i] = tmp[1];
            carry = tmp[0];
        }
        if (carry != '0')
            str1 = carry + str1;
        return str1;
    }

    string add(char a, char b, char carry) {
        int sum = int(a - '0') + int(b - '0') + int(carry - '0');
        switch (sum) {
            case 0 : return "00";
            case 1 : return "01";
            case 2 : return "10";
            case 3 : return "11";
        }
    }
};