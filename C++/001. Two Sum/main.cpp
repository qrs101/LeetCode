#include <iostream>
#include <vector>
#include <map>

using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int, int> index;
        int length = nums.size();
        for(int i = 0; i < length; i++) {
            int num = target - nums[i];
            if(index.find(num) != index.end()) {
                vector<int> res = {index[num], i};
                return res;
            } else{
                index.insert(map<int, int>::value_type(nums[i], i));
            }
        }
    }
};