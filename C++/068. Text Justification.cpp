#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::string> fullJustify(std::vector<std::string>& words, int maxWidth) {
        std::vector<std::string> res;
        int length = 0, pure_length = 0;
        int i, j;
        for (i = 0, j = 0; j < int(words.size()); j++) {
            if (length + int(words[j].size()) <= maxWidth) {
                length = length + int(words[j].size()) + 1;
                pure_length = pure_length + int(words[j].size());
            } else {
                if (j == i + 1) {
                    std::string line(unsigned(maxWidth - pure_length), ' ');
                    res.emplace_back(words[i] + line);
                } else {
                    int space = (maxWidth - pure_length) / (j - i - 1);
                    int over_space = (maxWidth - pure_length) % (j - i - 1);
                    std::string line = words[i];
                    for (int k = i + 1; k < j; k++) {
                        std::string tmp(unsigned(space), ' ');
                        if (over_space > 0) {
                            tmp += " ";
                            over_space--;
                        }
                        line += tmp + words[k];
                    }
                    res.emplace_back(line);
                }
                i = j;
                length = int(words[j].size()) + 1;
                pure_length = int(words[j].size());
            }
        }
        std::string line = words[i];
        for (int k = i + 1; k < j; k++)
            line += " " + words[k];
        line = line + std::string(maxWidth - line.size(), ' ');
        res.emplace_back(line);
        return res;
    }
};
