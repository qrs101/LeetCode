#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool compare(vector<int> a, vector<int> b) {
    int i;
    for (i = 0; i < a.size() && i < b.size(); i++) {
        if (a[i] > b[i])
            return true;
        else if (a[i] < b[i])
            return false;
    }
    if (i == a.size() && i == b.size())
        return true;
    if (i == a.size()) {
        vector<int> tmp (b.begin() + i, b.end());
        return compare(a, tmp);
    } else {
        vector<int> tmp (a.begin() + i, a.end());
        return compare(tmp, b);
    }
}

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<vector<int>> Nums (nums.size());
        bool tag = true;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 0) {
                Nums[i].push_back(0);
                continue;
            }
            tag = false;
            for (int num = nums[i]; num > 0; num = num / 10) {
                Nums[i].insert(Nums[i].begin(), num % 10);
            }
        }
        if (tag)
            return "0";

        sort(Nums.begin(), Nums.end(), compare);

        string res = "";
        for (auto num : Nums) {
            for (auto i : num) {
                res += to_string(i);
            }
        }
        return res;
    }
};

int main() {
    vector<int> nums {1,2,3,4,5,6,7,8,9,0};
    Solution so;
    string str = so.largestNumber(nums);
    cout << str << endl;
}