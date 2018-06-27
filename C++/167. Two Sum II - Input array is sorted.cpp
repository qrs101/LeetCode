#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int i = 0, j = int(numbers.size()) - 1;
        while (i < j) {
            if (numbers[i] + numbers[j] == target)
                break;
            if (numbers[i] + numbers[j] < target)
                i++;
            else
                j--;
        }
        return vector<int>{i + 1, j + 1};
    }
};