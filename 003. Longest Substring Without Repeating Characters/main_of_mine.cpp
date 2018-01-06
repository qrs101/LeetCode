#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int current_len = 0, max_len = 0, length = s.length();
        map<char, int> hash;
        for (int start = 0, end = 0; end < length; end++) {
            if (hash.find(s[end]) == hash.end()) {
                hash.insert(map<char, int>::value_type(s[end], end));
                current_len++;
            } else {
                int cur = hash[s[end]];
                current_len = end - cur;
                while (start < cur) {
                    hash.erase(s[start]);
                    start++;
                }
                start = cur + 1;
                hash[s[end]] = end;
            }
            if (max_len < current_len)
                max_len = current_len;
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