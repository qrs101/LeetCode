#include <iostream>
#include <vector>
#include <map>

class Solution {
public:
    std::vector<std::vector<std::string>> groupAnagrams(std::vector<std::string>& strs) {
        std::vector<std::vector<std::string>> res;
        std::map<std::string, std::vector<std::string>> M;
        for (auto str : strs) {
            std::string nums(26, '0');
            for (int i = 0; i < str.size(); i++) {
                nums[int(str[i] - 'a')]++;
            }
            M[nums].emplace_back(str);
        }
        for (auto i : M) {
            res.emplace_back(i.second);
        }
        return res;
    }
};