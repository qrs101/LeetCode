#include <iostream>
using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int si = 0, pi = 0;
        int sj = 0, pj = -1;
        while (si < s.size()) {
            if (pi < p.size() && (p[pi] == '?' || p[pi] == s[si])) {
                pi++;
                si++;
            } else if (pi < p.size() && p[pi] == '*') {
                pj = pi;
                sj = si - 1;
                pi++;
            } else if (pj != -1) {
                pi = pj + 1;
                sj++;
                si = sj;
            } else
                return false;
        }
        for (; pi < p.size() && p[pi] == '*'; pi++);
        if (pi == p.size())
            return true;
        return false;
    }
};