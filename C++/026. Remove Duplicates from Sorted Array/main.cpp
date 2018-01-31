#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        for (int i = 0; i < nums.size(); i++) {
            int j = i + 1;
            while (j < nums.size() && nums[i] == nums[j])
                j++;
            nums.erase(nums.begin() + i + 1, nums.begin() + j);
        }
        return nums.size();
    }
};

int main() {
    vector<int> a {1,1,2,3,4,5,5,5,6,7,8,9,9,9,9,10};
    Solution so;
    int res = so.removeDuplicates(a);
    cout << res << endl;

    return 0;
}