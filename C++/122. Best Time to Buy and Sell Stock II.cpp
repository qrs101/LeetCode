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
            if (prices[i] >= max) {
                max = prices[i];
            } else {
                ans += max - min;
                min = prices[i];
                max = prices[i];
            }
        }
        ans += max - min;
        return ans;
    }
};