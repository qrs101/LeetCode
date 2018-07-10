#include <iostream>
#include <vector>

class Solution {
public:
    double findMedianSortedArrays(std::vector<int>& nums1, std::vector<int>& nums2) {
        int N1 = int(nums1.size());
        int N2 = int(nums2.size());
        if (N1 < N2) {
            int tmp = N1;
            N1 = N2;
            N2 = tmp;
            nums1.swap(nums2);
        }
        int j = N2 / 2;
        int i = (N1 + N2) / 2 - j;
        int start = 0, end = N2 - 1;
        while (start <= end) {
            if (j != 0 && i != N1 && nums2[j - 1] > nums1[i])
                end = j - 1;
            else if (i != 0 && j != N2 && nums1[i - 1] > nums2[j])
                start = j + 1;
            else
                break;
            j = (start + end + 1) / 2;
            i = (N1 + N2) / 2 - j;
        }
        double Min;
        if (i == N1)
            Min = nums2[j];
        else if (j == N2)
            Min = nums1[i];
        else
            Min = std::min(nums1[i], nums2[j]);

        if ((N1 + N2) & 1 == 1)
            return Min;
        else {
            double Max;
            if (i == 0)
                Max = nums2[j - 1];
            else if (j == 0)
                Max = nums1[i - 1];
            else
                Max = std::max(nums1[i - 1], nums2[j - 1]);
            return (Max + Min) / 2;
        }
    }
};