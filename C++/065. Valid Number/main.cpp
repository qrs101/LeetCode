#include <iostream>
#include <regex>
using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        string str = s;
        for (int i = 0; i < str.size(); i++)
            if (str[i] != ' ') {
                str = str.substr(i);
                break;
            }
        for (auto i = int(str.size()); i > 0; i--)
            if (str[i - 1] != ' ') {
                str = str.substr(0, i);
                break;
            }
        bool b = false;
        string str1, str2;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == 'e' || str[i] == 'E') {
                str1 = str.substr(0, i);
                str2 = str.substr(i + 1);
                b = true;
                break;
            }
        }
        if (b)
            return isInteger(str2) && isFloat(str1);
        else
            return isFloat(str);
    }

    bool isInteger(string s) {
        if (s == "")
            return false;
        string str = s;
        if (s[0] == '+' || s[0] == '-')
            str = s.substr(1);
        if (str == "")
            return false;
        for (int i = 0; i < str.size(); i++)
            if (str[i] < '0' || str[i] > '9')
                return false;
        return true;
    }

    bool isFloat(string s) {
        if (s == "")
            return false;
        string str = s;
        if (s[0] == '+' || s[0] == '-')
            str = s.substr(1);
        if (str == "" || str == ".")
            return false;
        int num_of_dot = 0;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '.')
                num_of_dot++;
            else if (str[i] < '0' || str[i] > '9')
                return false;
            if (num_of_dot > 1)
                return false;
        }
        return true;
    }
};

int main() {
    Solution so;
    bool ans = so.isNumber("4e+");
    cout << ans <<endl;
}