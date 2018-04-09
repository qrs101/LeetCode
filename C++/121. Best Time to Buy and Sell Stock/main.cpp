#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        map<int, int> M;
        int ans = 0;
        for (auto i : prices) {
            if (M.empty())
                M.insert(map<int, int>::value_type(i, i));
            else {
                if (M.begin()->first > i)
                    M[i] = i;
                else
                    M[i] = M.begin()->first;
            }
        }
        for (auto i : M) {
            if (i.first - i.second > ans)
                ans = i.first - i.second;
        }
        return ans;
    }
};