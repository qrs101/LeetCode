#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = 0;
        while (i < m && n > 0) {
            if (nums1[i] >= nums2[0]) {
                for (int k = m; k > i; k--)
                    nums1[k] = nums1[k - 1];
                nums1[i] = nums2[0];
                nums2.erase(nums2.begin());
                n--;
                m++;
            }
            i++;
        }
        while (n > 0) {
            nums1[i] = nums2[0];
            nums2.erase(nums2.begin());
            i++;
            n--;
        }
    }
};

int main() {
    vector<int> nums1 {0};
    vector<int> nums2 {1};
    Solution so;
    so.merge(nums1, 0, nums2, 1);
    for (auto i : nums1)
        cout << i << endl;
    return 0;
}