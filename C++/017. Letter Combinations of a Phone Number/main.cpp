#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> d2l {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        if (digits.size() == 1) {
            int a = digits[0] - '0';
            if (d2l[a].size() == 0)
                res.push_back("");
            else {
                for (int i = 0; i < d2l[a].size(); i++) {
                    res.push_back(d2l[a].substr(i, 1));
                }
            }
        } else if (digits.size() > 1) {
            int a = digits[0] - '0';
            if (d2l[a].size() == 0)
                res = this->letterCombinations(digits.substr(1));
            else {
                vector<string> tmp = this->letterCombinations(digits.substr(1));
                for (int i = 0; i < d2l[a].size(); i++) {
                    for (auto j : tmp) {
                        res.push_back(d2l[a].substr(i, 1) + j);
                    }
                }
            }
        }

        return res;
    }
};

int main() {
    Solution so;
    vector<string> res = so.letterCombinations("23");
    for (auto i : res)
        cout << i << endl;
    return 0;
}