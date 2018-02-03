#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = 0, j = nums.size() - 1, m;
        int ans = -1;
        if (j == -1)
            return ans;
        if (nums[i] > nums[j]) {
            if (target < nums[i] && target> nums[j])
                return ans;
            while (nums[i] > nums[j] && j - i > 1) {
                m = (i + j) / 2;
                if (nums[i] < nums[m])
                    i = m;
                else
                    j = m;
            }

            if (target >= nums[0] && target <= nums[i]) {
                j = i;
                i = 0;
            } else if (target >= nums[j] && target <= nums[nums.size() - 1]) {
                i = j;
                j = nums.size() - 1;
            } else
                return ans;
        }

        while (i < j) {
            m = (i + j) / 2;
            if (nums[m] == target)
                return m;
            else if (target < nums[m])
                j = m - 1;
            else
                i = m + 1;
        }
        return ans;
    }
};

int main() {
    vector<int> a {1,3,5};
    Solution so;
    int ans = so.search(a, 3);
    cout << ans << endl;
    return 0;
}