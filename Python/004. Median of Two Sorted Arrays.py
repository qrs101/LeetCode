class Solution:
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        if len(nums1) < len(nums2):
            array1 = nums1
            array2 = nums2
        else:
            array1 = nums2
            array2 = nums1
        len1 = len(array1)
        len2 = len(array2)
        l = (len1 + len2) // 2

        start, end = 0, len1
        i, j = 0, 0
        while True:
            i = (start + end) // 2
            j = l - i
            A = i == 0 or j == len2 or array1[i - 1] <= array2[j]
            B = j == 0 or i == len1 or array2[j - 1] <= array1[i]
            if A and B:
                break
            elif A:
                start = i + 1
            elif B:
                end = i - 1

        if i == len1:
            right = array2[j]
        elif j == len2:
            right = array1[i]
        else:
            right = min(array1[i], array2[j])

        if (len1 + len2) % 2 == 1:
            return float(right)
        else:
            if i == 0:
                left = array2[j - 1]
            elif j == 0:
                left = array1[i - 1]
            else:
                left = max(array1[i - 1], array2[j - 1])
            return (left + right) / 2
