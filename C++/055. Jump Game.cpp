#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        if (n == 0 || n == 1)
            return true;
        int current_location = 0;
        while (current_location < n) {
            if (nums[current_location] == 0)
                return false;
            if (current_location + nums[current_location] >= n - 1)
                return true;
            int max = 0, next = current_location;
            for (int i = 1; i <= nums[current_location]; i++) {
                if (max < i + nums[current_location + i]) {
                    next = current_location + i;
                    max = i + nums[current_location + i];
                }
            }
            current_location = next;
        }
        return true;
    }
};

int main() {
    vector<int> nums {3,2,1,0,4};
    Solution so;
    bool ans = so.canJump(nums);
    cout << ans << endl;
    return 0;
}