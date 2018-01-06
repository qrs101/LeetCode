#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int length = s.length();
        int max_len = 0;
        map<char, int> hash;
        for (int start = -1, end = 0; end < length; end++) {
            if (hash.find(s[end]) != hash.end()) {
                int cur = hash[s[end]];
                if (start < cur)
                    start = cur;
                hash[s[end]] = end;
            } else {
                hash.insert(map<char, int>::value_type(s[end], end));
            }
            if (max_len < end - start)
                max_len = end - start;
        }
        return max_len;
    }
};

int main() {
    string s = "abcdcef";
    Solution so;
    int i = so.lengthOfLongestSubstring(s);
    cout << i << endl;

    return 0;
}