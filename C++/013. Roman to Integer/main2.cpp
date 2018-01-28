#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> hash = {
                {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
                {'C', 100}, {'D', 500}, {'M', 1000}
        };

        int ans = hash[s.back()];
        for (int i = s.size() - 2; i >= 0; i--) {
            if (hash[s[i]] < hash[s[i+1]]) {
                ans = ans - hash[s[i]];
            } else {
                ans = ans + hash[s[i]];
            }
        }

        return ans;
    }
};

int main() {
    Solution so;
    int ans = so.romanToInt("MMIII");
    cout << ans << endl;
}