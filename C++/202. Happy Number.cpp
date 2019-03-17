#include <iostream>
#include <unordered_set>

class Solution {
public:
    bool isHappy(int n) {
        std::unordered_set<int> set;
        for (int x = n; set.find(x) == set.end(); ) {
            if (x == 1)
                return true;
            set.insert(x);
            int sum = 0;
            while (x != 0) {
                int tmp = x % 10;
                sum += tmp * tmp;
                x = x / 10;
            }
            x = sum;
        }
        return false;
    }
};
