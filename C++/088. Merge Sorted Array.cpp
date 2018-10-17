#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        for (int i = 0, j; i < n; i++) {
            int num = nums2[i];
            for (j = 0; j < m + i && nums1[j] <= num; j++);
            for (int k = m + i - 1; k >= j; k--) {
                nums1[k + 1] = nums1[k];
            }
            nums1[j] = num;
        }
    }
};