#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    double soupServings(int N) {
        if (N >= 4500)
            return 1.0;
        int n = N / 25;
        if (N % 25 != 0)
            n++;
        cout << n << endl;
        vector<vector<double>> dp (n + 1, vector<double>(n + 1, -1));
        return helper(n, n, dp);
    }

    double helper(int A, int B, vector<vector<double>>& dp) {
        if (A <= 0 && B <= 0)
            return 0.5;
        else if (A <= 0 && B > 0)
            return 1;
        else if (B <= 0)
            return 0;
        if (dp[A][B] == -1) {
            double P1 = 0.25 * helper(A - 4, B, dp);
            double P2 = 0.25 * helper(A - 3, B - 1, dp);
            double P3 = 0.25 * helper(A - 2, B - 2, dp);
            double P4 = 0.25 * helper(A - 1, B - 3, dp);
            dp[A][B] = P1 + P2 + P3 + P4;
        }
        return dp[A][B];
    }
};

int main() {
    Solution so;
    double ans = so.soupServings(50);
    cout << ans << endl;
}