#include <iostream>
#include <vector>

class Solution {
public:
    std::vector<std::string> generateParenthesis(int n) {
        std::vector<std::string> res;
        helper(res, "", n, 0);
        return res;
    }

    void helper(std::vector<std::string> &res, std::string str, int left_par, int right_par) {
        if (left_par == 0 && right_par == 0) {
            res.push_back(str);
            return;
        }
        if (right_par > 0)
            helper(res, str + ")", left_par, right_par - 1);
        if (left_par > 0)
            helper(res, str + "(", left_par - 1, right_par + 1);
    }
};