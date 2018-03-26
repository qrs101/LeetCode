class Solution:
    def myAtoi(self, str):
        """
        :type str: str
        :rtype: int
        """
        if (len(str) == 0):
            return 0
        i = 0
        #删除前面所有的空格
        while i < len(str) and str[i] == ' ':
            i += 1
        str = str[i:]
        #判断符号
        positive = True
        if str[0] == '+':
            str = str[1:]
        elif str[0] == '-':
            str = str[1:]
            positive = False
        #删除后面无效字符
        i = 0
        while i < len(str) and str[i] >= '0' and str[i] <= '9':
            i += 1
        str = str[0 : i]
        if (len(str) == 0):
            return 0
        #计算数字
        ans = 0
        i -= 1
        t = 1
        while i >= 0:
            ans += int(str[i]) * t
            i -= 1
            t *= 10
        if positive:
            if ans > 2147483647:
                return 2147483647
            else:
                return ans
        else:
            if ans > 2147483648:
                return -2147483648
            else:
                return -ans