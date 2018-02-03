#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int i, j, tmp;
        for (i = n - 2; i >= 0; i--) {
            if (nums[i] >= nums[i + 1])
                continue;
            for (j = i + 1; j < n; j++)
                if (nums[j] <= nums[i])
                    break;
            tmp = nums[j - 1];
            nums[j - 1] = nums[i];
            nums[i] = tmp;
            break;
        }
        for (int x = i + 1, y = n - 1; x < y; x++, y--) {
            tmp = nums[y];
            nums[y] = nums[x];
            nums[x] = tmp;
        }
    }
};

int main() {
    vector<int> nums {1, 1, 5};
    Solution so;
    so.nextPermutation(nums);
    for (auto i : nums)
        cout << i <<  " ";
    return 0;
}