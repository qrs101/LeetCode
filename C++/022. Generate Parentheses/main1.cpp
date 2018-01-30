#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<vector<string>> res (n + 1);
        vector<vector<string>> tmp (n + 1);
        res[1].push_back("()");
        tmp[1].push_back("()");
        for (int i = 2; i <= n; i++) {
            for (auto str : res[i - 1]) {
                res[i].push_back("(" + str + ")");
                tmp[i].push_back("(" + str + ")");
            }
            for (int j = 1; j < i; j++) {
                for (auto str1 : tmp[j])
                    for (auto str2 : res[i - j])
                        res[i].push_back(str1 + str2);
            }
        }
        return res[n];
    }
};

int main() {
    Solution so;
    vector<string> res = so.generateParenthesis(5);
    cout << res.size() << endl;
    for (auto i : res){
        cout << i << endl;
    }
}