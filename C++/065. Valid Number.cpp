#include <iostream>

class Solution {
public:
    bool isNumber(std::string s) {
        int i;
        for (i = 0; i < int(s.size()) && s[i] == ' '; i++);
        s = s.substr(i);
        for (i = int(s.size()) - 1; i >= 0 && s[i] == ' '; i--);
        s = s.substr(0, i + 1);
        bool haveE = false;
        std::string str1, str2;
        for (i = 0; i < int(s.size()); i++) {
            if (s[i] == 'e' || s[i] == 'E') {
                str1 = s.substr(0, i);
                str2 = s.substr(i + 1);
                haveE = true;
                break;
            }
        }
        if (haveE)
            return isInteger(str2) && isFloat(str1);
        else
            return isFloat(s);
    }

    bool isInteger(std::string s) {
        if (s.size() == 0)
            return false;
        if (s[0] == '+' || s[0] == '-')
            s = s.substr(1);
        if (s.size() == 0)
            return false;
        for (int i = 0; i < int(s.size()); i++)
            if (s[i] < '0' || s[i] > '9')
                return false;
        return true;
    }

    bool isFloat(std::string s) {
        if (s.size() == 0)
            return false;
        if (s[0] == '+' || s[0] == '-')
            s = s.substr(1);
        if (s == "" || s == ".")
            return false;
        bool have_dot = false;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '.') {
                if (!have_dot)
                    have_dot = true;
                else
                    return false;
            } else if (s[i] < '0' || s[i] > '9')
                return false;
        }
        return true;
    }
};