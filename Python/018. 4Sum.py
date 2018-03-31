class Solution:
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        nums.sort()
        ans = []
        n = len(nums)
        cur = 0
        while cur <= n - 4:
            tmp1 = target - nums[cur]
            k = cur + 1
            while k <= n - 3:
                tmp2 = tmp1 - nums[k]
                i = k + 1
                j = n - 1
                while i < j:
                    if nums[i] + nums[j] == tmp2:
                        ans.append([nums[cur], nums[k] ,nums[i], nums[j]])
                        while i < j and nums[i + 1] == nums[i]:
                            i += 1
                        i += 1
                        while i < j and nums[j - 1] == nums[j]:
                            j -= 1
                        j -= 1
                    elif nums[i] + nums[j] < tmp2:
                        while i < j and nums[i + 1] == nums[i]:
                            i += 1
                        i += 1
                    else:
                        while i < j and nums[j - 1] == nums[j]:
                            j -= 1
                        j -= 1
                while k < n - 3 and nums[k + 1] == nums[k]:
                    k += 1
                k += 1
            while cur < n - 4 and nums[cur + 1] == nums[cur]:
                cur += 1
            cur += 1

        return ans
