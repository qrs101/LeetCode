#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {
        int start, end, num = 0;
        int n = int(t.size()), length = int(s.size() + 1);
        map<char, int> M;
        string ans = "";
        for (int k = 0; k < n; k++) {
            if (M.find(t[k]) == M.end()) {
                M.insert(map<char, int>::value_type(t[k], 1));
                num++;
            } else
                M[t[k]]++;
        }
        for (start = -1, end = 0; end < s.size(); end++) {
            if (M.find(s[end]) == M.end())
                continue;
            if (M[s[end]] == 1)
                num--;
            M[s[end]]--;
            while (start == - 1 || M[s[start]] < 0) {
                if (start != -1)
                    M[s[start]]++;
                start++;
                for(; start <= end && M.find(s[start]) == M.end(); start++);
            }
            if (num == 0 && length > end - start + 1) {
                length = end - start + 1;
                ans = s.substr(start, end - start + 1);
            }
        }
        return ans;
    }
};

int main() {
    Solution so;
    string ans = so.minWindow("ADOBECODEBANC", "ABC");
    cout << ans << "#" << endl;
    return 0;
}