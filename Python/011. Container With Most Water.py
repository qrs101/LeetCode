class Solution:
    def maxArea(self, height):
        """
        :type height: List[int]
        :rtype: int
        """
        start = 0
        end = len(height) - 1
        if end <= start:
            return 0
        ans = end * min(height[start], height[end])
        i = start
        j = end
        if height[start] <= height[end]:
            tag = True
        else:
            tag = False
        while i < j:
            if tag:
                if height[i] <= height[start]:
                    i += 1
                elif height[i] > height[start] and height[i] <= height[j]:
                    if height[i] * (j - i) > ans:
                        ans = height[i] * (j - i)
                        start = i
                        end = j
                    i += 1
                else:
                    if height[j] * (j - i) >= ans:
                        ans = height[j] * (j - i)
                        start = i
                        end = j
                    tag = False
            else:
                if height[j] <= height[end]:
                    j -= 1
                elif height[j] > height[end] and height[j] <= height[i]:
                    if height[j] * (j - i) >= ans:
                        ans = height[j] * (j - i)
                        start = i
                        end = j
                    j -= 1
                else:
                    if height[i] * (j - i) >= ans:
                        ans = height[i] * (j - i)
                        start = i
                        end = j
                    tag = True

        return ans

so = Solution()
ans = so.maxArea([76,155,15,188,180,154,84,34,187,142,22,5,27,183,111,128,50,58,2,112,179,2,100,111,115,76,134,120,118,103,31,146,58,198,134,38,104,170,25,92,112,199,49,140,135,160,20,185,171,23,98,150,177,198,61,92,26,147,164,144,51,196,42,109,194,177,100,99,99,125,143,12,76,192,152,11,152,124,197,123,147,95,73,124,45,86,168,24,34,133,120,85,81,163,146,75,92,198,126,191])
print(ans)