#include <iostream>
#include <vector>
#include <unordered_map>

class Solution {
public:
    std::vector<int> findSubstring(std::string s, std::vector<std::string>& words) {
        std::vector<int> res;
        std::unordered_map<std::string, int> str2num;
        if (int(s.size()) == 0 || int(words.size()) == 0 || int(words[0].size()) == 0)
            return res;
        for (int i = 0; i < int(words.size()); i++) {
            if (str2num.find(words[i]) == str2num.end())
                str2num.insert(std::unordered_map<std::string, int>::value_type(words[i], 1));
            else
                str2num[words[i]]++;
        }
        for (int i = 0; i <= int(s.size()) - int(words.size()) * int(words[0].size()); i++) {
            std::unordered_map<std::string, int> seen = str2num;
            bool tag = true;
            for (int j = 0; tag && j < int(words.size()); j++) {
                std::string str = s.substr(i + j * words[0].size(), words[0].size());
                if (seen.find(str) != seen.end() && seen[str] > 0) {
                    seen[str]--;
                } else {
                    tag = false;
                }
            }
            if (tag)
                res.push_back(i);
        }
        return res;
    }
};