class Solution:
    def reverse(self, x):
        """
        :type x: int
        :rtype: int
        """
        INT_MAX = 2147483647
        INT_MIN = -2147483648
        tag = False
        if x < 0:
            tag = True
            x = -x
        ans = 0
        while x != 0:
            r = x % 10
            x = x // 10
            ans = ans * 10 + r
        if tag:
            ans = -ans
        if ans > INT_MAX or ans < INT_MIN:
            return 0
        return ans