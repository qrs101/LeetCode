#include <iostream>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
    bool isValid(string s) {
        int n = s.size();
        if (n % 2 == 1)
            return false;
        unordered_map<char, char> M {
                {'(', ')'},
                {'[', ']'},
                {'{', '}'}
        };
        stack<char> S;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                S.push(s[i]);
            else {
                if (S.empty() == true || s[i] != M[S.top()])
                    return false;
                S.pop();
            }
        }
        if (S.empty() == true)
            return true;
        return false;
    }
};

int main() {
    Solution so;
    bool res = so.isValid("({})[]");
    cout << res << endl;
}