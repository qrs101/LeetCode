#include <iostream>
#include <algorithm>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> combinationSum(std::vector<int>& candidates, int target) {
        std::sort(candidates.begin(), candidates.end());
        return findSum(candidates, target);
    }

    std::vector<std::vector<int>> findSum(std::vector<int> candidates, int target) {
        std::vector<std::vector<int>> res;
        if (candidates.size() == 0 || target < candidates[0])
            return res;
        if (candidates[0] == target) {
            res.emplace_back(std::vector<int>{target});
            return res;
        }
        std::vector<std::vector<int>> tmp1 = findSum(std::vector<int>(candidates.begin() + 1, candidates.end()), target);
        std::vector<std::vector<int>> tmp2 = findSum(candidates, target - candidates[0]);
        for (auto &e : tmp2) {
            e.insert(e.begin(), candidates[0]);
        }
        res.insert(res.end(), tmp1.begin(), tmp1.end());
        res.insert(res.end(), tmp2.begin(), tmp2.end());
        return res;
    }
};