#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string getPermutation(int n, int k) {
        vector<int> array (n + 1, 1);
        vector<int> number (n + 1, 1);
        string ans = "";
        int t = k;
        for (int i = 2; i <= n; i++) {
            array[i] = i * array[i - 1];
            number[i] = i;
        }
        for (int i = n; i > 1; i--) {
            int tmp = array[i - 1];
            int loc = 1;
            while (t > tmp) {
                loc++;
                tmp = tmp + array[i - 1];
            }
            ans = ans + char(number[loc] + '0');
            number.erase(number.begin() + loc);
            t = t - tmp + array[i - 1];
        }
        ans = ans + char(number[1] + '0');
        return ans;
    }
};

int main() {
    Solution so;
    string ans = so.getPermutation(4, 7);
    cout << ans << endl;
    return 0;
}