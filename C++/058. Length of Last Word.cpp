#include <iostream>
using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int ans = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ')
                ans++;
            else {
                while (s[i] == ' ' && i < s.size())
                    i++;
                if (i == s.size())
                    break;
                ans = 0;
                i--;
            }
        }
        return ans;
    }
};