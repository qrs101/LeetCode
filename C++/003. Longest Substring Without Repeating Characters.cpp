#include <iostream>
#include <map>

class Solution {
public:
    int lengthOfLongestSubstring(std::string s) {
        int length = int(s.size());
        int res = 0;
        std::map<char, int> m;
        for (int start = 0, end = 0; end < length; end++) {
            if (m.find(s[end]) == m.end()) {
                m.insert(std::map<char, int>::value_type(s[end], end));
            } else {
                if (start <= m[s[end]])
                    start = m[s[end]] + 1;
                m[s[end]] = end;
            }
            if (res < end - start + 1)
                res = end - start + 1;
        }
        return res;
    }
};