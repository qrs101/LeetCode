#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for (int i = 0; i < int(nums.size()) - 1; i++) {
            if (nums[i] != nums[i + 1])
                continue;
            int j = i + 2;
            while (j < nums.size() && nums[j] == nums[i])
                nums.erase(nums.begin() + j);
            i = j - 1;
        }
        return int(nums.size());
    }
};

int main() {
    vector<int> nums;
    Solution so;
    int ans = so.removeDuplicates(nums);
    cout << ans << endl;
    return 0;
}