#include<iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = int(s.size()) - 1;
        while (i < j) {
            if (!(s[i] >= 'a' && s[i] <= 'z' || s[i] >= '0' && s[i] <= '9' || s[i] >= 'A' && s[i] <= 'Z')) {
                i++;
                continue;
            }
            if (!(s[j] >= 'a' && s[j] <= 'z' || s[j] >= '0' && s[j] <= '9' || s[j] >= 'A' && s[j] <= 'Z')) {
                j--;
                continue;
            }
            if (equal(s[i], s[j])) {
                i++;
                j--;
                continue;
            }
            return false;
        }
        return true;
    }

    bool equal(char i, char j) {
        if (i == j)
            return true;
        if (i >= 'A' && i <= 'Z')
            i = char('a' + int(i - 'A'));
        if (j >= 'A' && j <= 'Z')
            j = char('a' + int(j - 'A'));
        if (i == j)
            return true;
        return false;
    }
};