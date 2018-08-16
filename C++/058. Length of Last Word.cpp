#include <iostream>

class Solution {
public:
    int lengthOfLastWord(std::string s) {
        int i, j;
        for (j = int(s.size()) - 1; j >= 0 && s[j] == ' '; j--);
        for (i = j; i >= 0 && s[i] != ' '; i--);
        return j - i;
    }
};