#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        auto n = int(gas.size());
        for (int i = 0; i < n; i++)
            gas[i] = gas[i] - cost[i];
        for (int i = 0; i < n; i++) {
            if (gas[i] < 0)
                continue;
            int num = gas[i];
            for (int j = 1; j < n; j++) {
                int t = (i + j) % n;
                num += gas[t];
                if (num < 0) {
                    if (t < i)
                        return -1;
                    else {
                        i = t - 1;
                        break;
                    }
                }
            }
            if (num >= 0)
                return i;
        }
        return -1;
    }
};