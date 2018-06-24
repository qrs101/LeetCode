#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int i = 0;
        int j = int(nums.size()) - 1;
        if (i > j)
            return false;
        while (i < j) {
            int m = (i + j) / 2;
            if (nums[m] == target)
                return true;
            if (nums[m] > nums[i]) {
                if (target >= nums[i] && target < nums[m])
                    j = m - 1;
                else
                    i = m;
            } else if (nums[m] < nums[i]) {
                if (target > nums[m] && target <= nums[j])
                    i = m + 1;
                else
                    j = m;
            } else
                i++;
        }
        if (nums[i] == target)
            return true;
        return false;
    }
};

int main() {
    vector<int> nums {1,1,3,1};
    Solution so;
    bool ans = so.search(nums, 1);
    cout << ans << endl;
    return 0;
}