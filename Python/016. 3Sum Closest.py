class Solution:
    def threeSumClosest(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: int
        """
        nums.sort()
        print(nums)
        n = len(nums)
        ans = nums[0] + nums[1] + nums[n - 1]
        cur = 0
        i = 1
        j = n - 1
        while cur < n - 2:
            if nums[cur] + nums[cur + 1] + nums[cur + 2] >= target:
                a = abs(target - ans)
                b = abs(target - nums[cur] - nums[cur + 1] - nums[cur + 2])
                if a > b:
                    ans = nums[cur] + nums[cur + 1] + nums[cur + 2]
                break
            while i < j:
                tmp = nums[cur] + nums[i] + nums[j]
                a = abs(target - ans)
                b = abs(target - tmp)
                if a > b:
                    ans = tmp
                if tmp == target:
                    return tmp
                elif tmp < target:
                    while i < j and nums[i + 1] == nums[i]:
                        i += 1
                    i += 1
                else:
                    while i < j and nums[j - 1] == nums[j]:
                        j -= 1
                    j -= 1
            while cur < n - 3 and nums[cur + 1] == nums[cur]:
                cur += 1
            cur += 1
            i = cur + 1
            j = n - 1
        return ans

so = Solution()
ans = so.threeSumClosest([1,1,-1,-1,3], -1)
print(ans)