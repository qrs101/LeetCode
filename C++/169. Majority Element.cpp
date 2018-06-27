#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> m;
        for (auto i : nums) {
            if (m.find(i) == m.end())
                m.insert(map<int, int>::value_type(i, 1));
            else
                m[i]++;
        }
        int res = 0;
        for (auto i : m) {
            if (i.second > nums.size() / 2) {
                res = i.first;
                break;
            }
        }
        return res;
    }
};