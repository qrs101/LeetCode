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
        //dp[i,j]==true表示pattern_[i:]和text[j:]能匹配上
        int m = pattern_.length();
        int n = text.length();
        vector<vector<bool>> dp (m+1, vector<bool>(n+1));
        //初始值dp[m,0]-dp[m,n-1]初始值为false,dp[m,n]初始值为true
        //表示pattern_[i:]为空，text[j:]不为空，则匹配不上，都为空能匹配上
        for (int i = 0; i < n; i++)
            dp[m][i] = false;
        dp[m][n] = true;

        //为dp[i,j]赋值
        for (int i = m-1; i >= 0; i--) {
            //判断dp[i,n]是否为true, dp[i,n]为true的条件是star[i:]全都为true
            dp[i][n] = true;
            for (int k = i; k <= m-1; k++) {
                if (star[k] != true) {
                    dp[i][n] = false;
                    break;
                }
            }
            //判断dp[i,j]
            for (int j = n-1; j >= 0; j--) {
                //pattern_[i]后不跟*
                if (star[i] == false) {
                    if ((pattern_[i] == '.' || pattern_[i] == text[j]) && dp[i+1][j+1] == true)
                        dp[i][j] = true;
                    else
                        dp[i][j] = false;
                } else { //pattern_[i]后跟*
                    dp[i][j] = false;
                    if (dp[i+1][j] == true)
                        dp[i][j] = true;
                    else {
                        for (int k = j; k < n; k++) {
                            if (pattern_[i] == '.' || pattern_[i] == text[k]) {
                                if (dp[i+1][k+1] == true) {
                                    dp[i][j] = true;
                                    break;
                                }
                            } else {
                                dp[i][j] = false;
                                break;
                            }
                        }
                    }
                }
            }
        }

        return dp[0][0];
    }
};

int main() {
    Solution so;
    bool b = so.isMatch("aaab", "c*.a*b*");
    cout << b << endl;
}