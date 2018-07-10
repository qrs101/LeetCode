#include <iostream>
#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int>& prices) {
        int res = 0;
        if (prices.size() == 0)
            return res;
        int min = prices[0], max = prices[0];
        for (int i = 1; i < int(prices.size()); i++) {
            if (prices[i] < min) {
                min = prices[i];
                max = prices[i];
            } else if (prices[i] > max) {
                max = prices[i];
            }
            if (max - min > res)
                res = max - min;
        }
        return res;
    }

    /* another method
    int maxProfit(std::vector<int>& prices) {
        int res = 0;
        if (prices.size() == 0)
            return res;
        int min = prices[0];
        for (int i = 1; i < int(prices.size()); i++) {
            if (prices[i] < min)
                min = prices[i];
            if (prices[i] - min > res)
                res = prices[i] - min;
        }
        return res;
    }
    */
};