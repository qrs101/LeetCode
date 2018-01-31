#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == val) {
                nums.erase(nums.begin() + i);
                i--;
            }
        }
        return nums.size();
    }
};

int main() {
    vector<int> a {1,2,3,3,4,1,2,5,32,22};
    Solution so;
    int res = so.removeElement(a, 1);
    cout << res << endl;
}