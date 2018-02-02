#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string, int> Num;
        int m = s.size(), n = words.size(), k = words[0].size();
        vector<int> ans;
        if (m == 0 || n == 0 || k == 0)
            return ans;
        for (int i = 0; i < n; i++) {
            if (Num.find(words[i]) == Num.end())
                Num.insert(unordered_map<string, int>::value_type(words[i], 1));
            else
                Num[words[i]]++;
        }

        for (int i = 0; i <= m - k * n; i++) {
            unordered_map<string, int> Seen = Num;
            bool tag = true;
            for (int j = 0; j < n; j++) {
                int tmp = i + j * k;
                string str = s.substr(tmp, k);
                if (Seen.find(str) != Seen.end() && Seen[str] > 0) {
                    Seen[str]--;
                } else {
                    tag  =false;
                    break;
                }
            }
            if (tag)
                ans.push_back(i);
        }
        return ans;
    }
};

int main() {
    string s = "a";
    vector<string> w {"a"};
    Solution so;
    vector<int> res = so.findSubstring(s, w);
    for (auto i : res)
        cout << i << " ";
    return 0;
}