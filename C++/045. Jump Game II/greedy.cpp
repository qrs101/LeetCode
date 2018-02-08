#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
        auto n = int(nums.size());
        if (n == 0 || n == 1)
            return 0;
        int start = 0, end = n - 1, ans = 0;
        while (true) {
            if (start + nums[start] >= end) {
                ans++;
                break;
            }
            int tmp = 0, next = 0;
            for (int i = 1; i <= nums[start]; i++) {
                if (tmp < i + nums[start + i]) {
                    tmp = i + nums[start + i];
                    next = i;
                }
            }
            start = start + next;
            ans++;
        }
        return ans;
    }
};

int main() {
    vector<int> nums {1,1,2};
    Solution so;
    auto ans = so.jump(nums);
    cout << ans << endl;
    return 0;
}