#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans = 0;
        if (prices.size() == 0)
            return ans;
        int min = prices[0], max = prices[0];
        for (int i = 1; i < int(prices.size()); i++) {
            if (prices[i] < min) {
                min = prices[i];
                max = prices[i];
            } else if (prices[i] > max) {
                max = prices[i];
            }
            if (max - min > ans)
                ans = max - min;
        }
        return ans;
    }

    /* HashTable
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
    */
};