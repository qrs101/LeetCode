class Solution:
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        d = dict()
        length = len(nums)
        for i in range(length):
            if nums[i] in d:
                l = [d[nums[i]], i]
                return l
            else:
                d[target - nums[i]] = i