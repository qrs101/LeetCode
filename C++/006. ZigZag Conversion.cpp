#include <iostream>
#include <vector>

class Solution {
public:
    std::string convert(std::string s, int numRows) {
        if (numRows == 1)
            return s;
        std::string tmp[numRows];
        std::string res;
        bool tag = true;
        for (int i = 0, n = 0; i < int(s.size()); i++) {
            tmp[n] = tmp[n] + s[i];
            if (tag) {
                n++;
                if (n == numRows-1)
                    tag = false;
            } else {
                n--;
                if (n == 0)
                    tag = true;
            }
        }
        for (int i = 0; i < numRows; i++)
            res = res + tmp[i];
        return res;
    }
};