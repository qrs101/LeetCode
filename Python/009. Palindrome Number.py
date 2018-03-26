class Solution:
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if (x < 0):
            return False
        i = 0
        a = x
        while a != 0:
            a = a // 10
            i += 1
        j = False
        if i % 2 == 1:
            j = True
        a = x
        b = 0
        i = i // 2
        while i > 0:
            tmp = a % 10
            a //= 10
            b = b * 10 + tmp
            i -= 1
        if j:
            a //= 10
        if a == b:
            return True
        return False

so = Solution()
ans = so.isPalindrome(22322)
print(ans)