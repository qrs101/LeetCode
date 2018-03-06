#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> ans;
        ans.push_back(0);
        if (n == 0)
            return ans;
        vector<int> bit (n, 0);
        vector<int> weight (n, 1);
        for (int i = 1; i < n; i++)
            weight[i] = 2 * weight[i - 1];
        vector<bool> tag (weight[n - 1] * 2, false);
        tag[0] = true;
        bool T = true;
        while (T) {
            int i;
            for (i = 0; i < n; i++) {
                bit[i] = 1 - bit[i];
                int tmp = judge(bit, weight, tag, n);
                if (tmp == -1) {
                    bit[i] = 1 - bit[i];
                    continue;
                }
                ans.push_back(tmp);
                tag[tmp] = true;
                break;
            }
            if (i == n)
                T = false;
        }
        return ans;
    }

    int judge(vector<int>& bit, vector<int>& weight, vector<bool>& tag, int n) {
        int sum = 0;
        for (int i = 0; i < n; i++) {
            sum += bit[i] * weight[i];
        }
        if (tag[sum])
            return -1;
        return sum;
    }
};