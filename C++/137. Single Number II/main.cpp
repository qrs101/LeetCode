#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        auto n = int(nums.size());
        int t = 1;
        int res = 0;
        for (int i = 0; i < 32; i++) {
            int s = 0;
            for (int j = 0; j < n; j++) {
                s += (nums[j] & 1);
                nums[j] >>= 1;
            }
            s %= 3;
            res += s * t;
            t *= 2;
        }
        return res;
    }
};

int main() {
    Solution so;
    vector<int> nums {0,1,0,1,0,1,99};
    int res = so.singleNumber(nums);
    cout << res << endl;
}