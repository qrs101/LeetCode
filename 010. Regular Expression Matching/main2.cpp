#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isMatch(string text, string pattern) {
        //分离正则字符串，字符后面带*标记为true，否则标记为false
        int len = pattern.length();
        string pattern_;
        vector<bool> star;
        for (int i = 0; i < len; i++) {
            if (pattern[i] != '*') {
                pattern_ = pattern_ + pattern[i];
                if (pattern[i + 1] == '*') {
                    star.push_back(true);
                } else {
                    star.push_back(false);
                }
            }
        }
        int m = pattern_.length();
        int n = text.length();
        if (0 == m && 0 == n) {
            return true;
        } else if (0 == m) {
            return false;
        } else if (0 == n) {
            for (int k = 0; k < m; k++) {
                if (star[k] == false) {
                    return false;
                }
            }
            return true;
        } else {
            if (star[0] == false) {
                if (text[0] == pattern_[0] || pattern_[0] == '.')
                    return this->isMatch(text.substr(1), pattern.substr(1));
                else
                    return false;
            } else {
                if (this->isMatch(text, pattern.substr(2)) == true)
                    return true;
                else {
                    for (int j = 0; j < n; j++) {
                        if (text[j] == pattern_[0] || pattern_[0] == '.') {
                            if (this->isMatch(text.substr(j+1), pattern.substr(2)) == true)
                                return true;
                        } else {
                            return false;
                        }
                    }
                    return false;
                }
            }
        }

    }
};

int main() {
    Solution so;
    bool b = so.isMatch("aacda", ".*");
    cout << b << endl;
}