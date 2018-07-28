#include <iostream>

class Solution {
public:
    int strStr(std::string haystack, std::string needle) {
        for (int i = 0; i <= int(haystack.size()) - int(needle.size()); i++) {
            if (haystack.substr(i, int(needle.size())) == needle)
                return i;
        }
        return -1;
    }
    /* KMP算法
    int strStr(std::string haystack, std::string needle) {
        if (needle.size() == 0)
            return 0;
        else if (haystack.size() == 0)
            return  -1;
        std::vector<int> next (needle.size(), -1);
        for (int i = 1; i < needle.size(); i++) {
            if (next[i - 1] != -1 && needle[i - 1] == needle[next[i - 1]])
                next[i] = next[i - 1] + 1;
            else {
                int j = next[i - 1];
                while (j != -1 && needle[i - 1] != needle[j])
                    j = next[j];
                next[i] = j + 1;
            }
        }
        for (int i = 0, j = 0; i < haystack.size(); i++, j++) {
            if (haystack[i] != needle[j] && next[j] == -1)
                j--;
            else if (haystack[i] != needle[j] && next[j] != -1) {
                j = next[j] - 1;
                i--;
            }
            if (j == needle.size() - 1 && haystack[i] == needle[j])
                return i - j;
        }
        return -1;
    }
    */
};