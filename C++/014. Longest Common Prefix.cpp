#include <iostream>
#include <vector>

class Solution {
public:
    std::string longestCommonPrefix(std::vector<std::string>& strs) {
        if (int(strs.size()) == 0)
            return "";
        for (int i = 0; i < int(strs[0].size()); i++) {
            for (int k = 1; k < int(strs.size()); k++) {
                if (i >= int(strs[k].size()) || strs[k][i] != strs[0][i]) {
                    return strs[0].substr(0, i);
                }
            }
        }
        return strs[0];
    }
};