#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int, int> M;
        for (auto i : nums) {
            if (M.find(i) == M.end())
                M.insert(map<int, int>::value_type(i, 1));
        }
        int ans = 0;
        for (auto ite = M.rbegin(); ite != M.rend(); ite++) {
            if (M.find(ite->first + 1) != M.end())
                ite->second = M[ite->first + 1] + 1;
            if (ans < ite->second)
                ans = ite->second;
        }
        return ans;
    }
};