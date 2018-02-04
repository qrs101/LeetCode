#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = int(nums.size()) - 1;
        if (n == -1 || target < nums[0])
            return 0;
        if (target > nums[n])
            return n + 1;
        int i = 0, j = n;
        while (i < j) {
            int m = (i + j) / 2;
            if (nums[m] == target)
                return m;
            else if (nums[m] > target)
                j = m - 1;
            else
                i = m + 1;
        }
        if (nums[i] >= target)
            return i;
        else
            return i + 1;
    }
};

int main() {
    vector<int> nums {1,2,3,4,5};
    Solution so;
    int ans = so.searchInsert(nums, 3);
    cout << ans << endl;
    return 0;
}