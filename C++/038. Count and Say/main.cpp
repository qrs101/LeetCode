#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        vector<string> str;
        str.push_back("");
        str.push_back("1");
        for (int i = 2; i <= n; i++) {
            string tmp = str[i - 1];
            str.push_back("");
            for (int j = 0; j < tmp.size(); j++) {
                int num = 1;
                while (j + 1 < tmp.size() && tmp[j + 1] == tmp[j]) {
                    j++;
                    num++;
                }
                str[i] = str[i] + to_string(num) + tmp[j];
            }
        }
        return str[n];
    }
};

int main() {
    Solution so;
    string ans = so.countAndSay(6);
    cout << ans << endl;
    return 0;
}