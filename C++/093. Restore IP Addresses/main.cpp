#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        return IP(s, 4);
    }

    vector<string> IP(string s, int n) {
        vector<string> ans;
        if (s.size() == 0)
            return ans;
        if (n == 1) {
            if (s.size() > 3)
                return ans;
            int i = stoi(s);
            if (s.size() == 3 && i >= 100 && i <= 255)
                ans.push_back(s);
            else if (s.size() == 2 && i >= 10 && i <= 99)
                ans.push_back(s);
            else if (s.size() == 1 && i >= 0 && i <= 9)
                ans.push_back(s);
            return ans;
        }
        vector<string> tmp;
        int i;
        if (s.size() >= 1) {
            i = stoi(s.substr(0, 1));
            if (i >= 0 && i <= 9) {
                tmp = IP(s.substr(1), n - 1);
                for (auto j : tmp)
                    ans.push_back(s.substr(0, 1) + "." + j);
            }
        }
        if (s.size() >= 2) {
            i = stoi(s.substr(0, 2));
            if (i >= 10 && i <= 99) {
                tmp = IP(s.substr(2), n - 1);
                for (auto j : tmp)
                    ans.push_back(s.substr(0, 2) + "." + j);
            }
        }
        if (s.size() >= 3) {
            i = stoi(s.substr(0, 3));
            if (i >= 100 && i <= 255) {
                tmp = IP(s.substr(3), n - 1);
                for (auto j : tmp)
                    ans.push_back(s.substr(0, 3) + "." + j);
            }
        }
        return ans;
    }
};

int main() {
    string s = "1111";
    Solution so;
    vector<string> ans = so.restoreIpAddresses(s);
    for (auto i : ans)
        cout << i << endl;
    return 0;
}