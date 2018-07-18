#include <iostream>
#include <climits>

class Solution {
public:
    int myAtoi(std::string str) {
        int k;
        //删除前面所有空白字符
        for (k = 0; k < int(str.size()) && str[k] == ' '; k++);
        str = str.substr(k);
        //判断符号
        int symbol = 1;
        if (str.size() > 0 && str[0] == '+')
            str = str.substr(1);
        else if (str.size() > 0 && str[0] == '-') {
            symbol = -1;
            str = str.substr(1);
        }
        //截取有效字符
        for (k = 0; k < int(str.size()) && str[k] >= '0' && str[k] <= '9'; k++);
        str = str.substr(0, k);
        //转换成数字
        long res = 0;
        for (k = 0; k < int(str.size()); k++) {
            res *= 10;
            res += str[k] - '0';
            if (symbol * res > INT32_MAX)
                return INT32_MAX;
            if (symbol * res < INT32_MIN)
                return INT32_MIN;
        }
        return int(symbol * res);
    }
};