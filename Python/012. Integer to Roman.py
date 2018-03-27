class Solution:
    def intToRoman(self, num):
        """
        :type num: int
        :rtype: str
        """
        a = ['', 'I', 'II', 'III', 'IV', 'V', 'VI', 'VII', 'VIII', 'IX']
        b = ['', 'X', 'XX', 'XXX', 'XL', 'L', 'LX', 'LXX', 'LXXX', 'XC']
        c = ['', 'C', 'CC', 'CCC', 'CD', 'D', 'DC', 'DCC', 'DCCC', 'CM']
        d = ['', 'M', 'MM', 'MMM']
        bit = []
        bit.append(a)
        bit.append(b)
        bit.append(c)
        bit.append(d)
        ans = ""
        for i in range(4):
            ans = bit[i][num % 10] + ans
            num = num // 10
        return ans

so = Solution()
ans = so.intToRoman(10)
print(ans)