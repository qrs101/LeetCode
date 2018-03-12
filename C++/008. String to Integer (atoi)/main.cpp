#include <iostream>
#include <climits>
using namespace std;

class Solution {
public:
    int myAtoi(string str) {
        int k;
        string s =str;
        //删除前面所有空白字符
        for (k = 0; k < int(str.size()) && str[k] == ' '; k++);
        s = s.substr(k);
        //判断符号
        int positive = 1;
        if (s.size() > 0 && s[0] == '+')
            s = s.substr(1);
        else if (s.size() > 0 && s[0] == '-') {
            positive = -1;
            s = s.substr(1);
        }
        //删除后面额外字符
        for (k = 0; k < int(s.size()) && s[k] >= '0' && s[k] <= '9'; k++);
        s = s.substr(0, k);
        //删除前面所有的0
        for (k = 0; k < int(s.size()) && s[k] == '0'; k++);
        s = s.substr(k);
        //判断s是否有效
        if (s.size() == 0 || s[0] < '0' || s[0] > '9')
            return 0;
        //判断数字长度是不是超出限制
        if (s.size() > 10) {
            if (positive == 1)
                return INT_MAX;
            else
                return INT_MIN;
        }
        //计算该数字
        long long ans = 0;
        long long l = 1;
        for (int i = int(s.size()) - 1; i >= 0; i--, l *= 10) {
            int tmp = s[i] - '0';
            ans += l * tmp;
        }
        ans = ans * positive;
        //返回
        if (ans > INT_MAX)
            return INT_MAX;
        if (ans < INT_MIN)
            return INT_MIN;
        return int(ans);
    }
};