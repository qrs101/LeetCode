#include <iostream>
#include <vector>
#include <map>

class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::map<int, int> m;
        std::vector<int> res (2, 0);
        for(int i = 0; i < int(nums.size()); i++) {
            if(m.find(nums[i]) != m.end()) {
                res[0] = m[nums[i]];
                res[1] = i;
                break;
            }
            m.insert(std::map<int, int>::value_type(target - nums[i], i));
        }
        return res;
    }
};