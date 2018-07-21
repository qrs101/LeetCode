#include <iostream>
#include <vector>
#include <map>

class Solution {
private:
    std::map<char, std::vector<std::string>> m {
            {'2', std::vector<std::string>{"a", "b", "c"}},
            {'3', std::vector<std::string>{"d", "e", "f"}},
            {'4', std::vector<std::string>{"g", "h", "i"}},
            {'5', std::vector<std::string>{"j", "k", "l"}},
            {'6', std::vector<std::string>{"m", "n", "o"}},
            {'7', std::vector<std::string>{"p", "q", "r", "s"}},
            {'8', std::vector<std::string>{"t", "u", "v"}},
            {'9', std::vector<std::string>{"w", "x", "y", "z"}}
    };
public:
    std::vector<std::string> letterCombinations(std::string digits) {
        std::vector<std::string> res;
        if (int(digits.size()) == 0)
            return res;
        if (int(digits.size()) == 1)
            return m[digits[0]];
        std::vector<std::string> tmp = letterCombinations(digits.substr(1));
        for (auto i : m[digits[0]]) {
            for (auto j : tmp) {
                res.push_back(i + j);
            }
        }
        return res;
    }
};