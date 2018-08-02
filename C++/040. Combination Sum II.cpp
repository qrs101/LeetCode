#include <iostream>
#include <algorithm>
#include <vector>

class Solution {
public:
    std::vector<std::vector<int>> combinationSum2(std::vector<int>& candidates, int target)  {
        sort(candidates.begin(), candidates.end());
        return findSum(candidates, target);
    }

    std::vector<std::vector<int>> findSum(std::vector<int> candidates, int target) {
        std::vector<std::vector<int>> res;
        if (int(candidates.size()) == 0 || target < candidates[0])
            return res;
        int loc = 1;
        for (; loc < int(candidates.size()) && candidates[loc] == candidates[loc - 1]; loc++);
        std::vector<int> cur_candidates;
        std::vector<int> left_candidates(candidates.begin() + loc, candidates.end());
        for (int i = 0, num = 0; i <= loc; i++, num += candidates[0]) {
            if (target - num == 0) {
                res.emplace_back(cur_candidates);
            } else if (target - num > 0) {
                std::vector<std::vector<int>> tmp = findSum(left_candidates, target - num);
                for (auto &array : tmp)
                    array.insert(array.begin(), cur_candidates.begin(), cur_candidates.end());
                res.insert(res.end(), tmp.begin(), tmp.end());
            } else {
                break;
            }
            cur_candidates.emplace_back(candidates[0]);
        }
        return res;
    }
};