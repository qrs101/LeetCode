#include<iostream>
#include<map>
using namespace std;

class Solution {
public:
    string convertToTitle(int n) {
        map<int, char> m;
        for (int i = 0; i < 26; i++) {
            m.insert(map<int, char>::value_type(i + 1, char('A' + i)));
        }
        m.insert(map<int, char>::value_type(0, 'Z'));
        string res = "";
        while (n != 0) {
            int t = n % 26;
            res = m[t] + res;
            n = n / 26;
            if (t == 0) {
                n--;
            }
        }
        return res;
    }
};

int main() {
    Solution so;
    string res = so.convertToTitle(52);
    cout << res << endl;
}