class Solution:
    def isHappy(self, n: int) -> bool:
        set = {}
        x = n
        while set.get(x) is None:
            if x == 1:
                return True
            set[x] = True
            sum = 0
            while x != 0:
                tmp = x % 10
                sum += tmp * tmp
                x = x // 10
            x = sum
        return False
