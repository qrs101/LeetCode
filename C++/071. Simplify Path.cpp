#include <iostream>
#include <stack>
using namespace std;

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> S;
        string str = '/' + path + '/';
        for (int i = -1, j = 0; j < str.size(); j++) {
            if (str[j] != '/' && str[j - 1] == '/')
                i = j;
            if (str[j] == '/' && str[j - 1] != '/'  && i != -1) {
                string tmp = str.substr(i, j - i);
                if (tmp == ".")
                    continue;
                else if (tmp == "..") {
                    if (!S.empty())
                        S.pop();
                } else
                    S.push(tmp);
            }
        }

        if (S.empty())
            return "/";
        string ans = "";
        while (!S.empty()) {
            ans = "/" + S.top() + ans;
            S.pop();
        }
        return ans;
    }
};

int main() {
    Solution so;
    string ans = so.simplifyPath("/.");
    cout << ans << endl;
    return 0;
}