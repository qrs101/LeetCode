class Solution:
    def threeSum(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        nums = sorted(nums)
        n = len(nums)
        ans = []
        cur = 0
        while cur < n - 2:
            target = -nums[cur]
            i = cur + 1
            j = n - 1
            while i < j:
                if nums[i] + nums[j] == target:
                    ans.append([nums[cur], nums[i], nums[j]])
                    while i < j and nums[i + 1] == nums[i]:
                        i += 1
                    while i < j and nums[j - 1] == nums[j]:
                        j -= 1
                    i += 1
                    j -= 1
                elif nums[i] + nums[j] < target:
                    while i < j and nums[i + 1] == nums[i]:
                        i += 1
                    i += 1
                else:
                    while i < j and nums[j - 1] == nums[j]:
                        j -= 1
                    j -= 1
            while cur < n - 2 and nums[cur + 1] == nums[cur]:
                cur += 1
            cur += 1
        return ans

so = Solution()
ans = so.threeSum([0,0,0,0])
print(ans)