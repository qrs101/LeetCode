#include <iostream>
#include <vector>
#include <climits>
using namespace std;

struct bucket {
    bool empty = true;
    int min_number = INT_MAX;
    int max_number = INT_MIN;
};

class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int res = 0;
        auto n = int(nums.size());
        if (n < 2)
            return res;
        int Min = nums[0], Max = nums[0];
        for (auto num : nums) {
            Min = min(Min, num);
            Max = max(Max, num);
        }

        int size = (Max - Min) / (n - 1);
        if (size == 0)
            size++;
        vector<bucket> b ((Max - Min) / size + 1);
        for (auto num : nums) {
            int i = (num - Min) / size;
            b[i].empty = false;
            b[i].min_number = min(b[i].min_number, num);
            b[i].max_number = max(b[i].max_number, num);
        }
        int last = Min;
        for (auto i : b) {
            if (!i.empty) {
                res = max(res, i.min_number - last);
                last = i.max_number;
            }
        }
        return res;
    }
};

int main() {
    vector<int> nums{3,6,9,1,10,20};
    Solution so;
    int res = so.maximumGap(nums);
    cout << res << endl;
}