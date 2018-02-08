#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        map<vector<int>, vector<string>> M;
        for (auto str : strs) {
            vector<int> nums(26, 0);
            for (int i = 0; i < str.size(); i++) {
                auto j = int(str[i] - 'a');
                nums[j]++;
            }
            M[nums].push_back(str);
        }
        for (auto i : M) {
            ans.push_back(i.second);
        }
        return ans;
    }
};

int main() {
    map<int, string> M;
    M[1] = "abc";
    M[2] = "bcd";
    for (auto i : M)
        cout << i.first << " " << i.second << endl;
}