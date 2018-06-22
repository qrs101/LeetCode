#include <iostream>
#include <unordered_set>
#include <vector>
using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> list;
        for (auto i : wordList)
            list.insert(i);
        if (list.find(endWord) == list.end())
            return 0;
        list.erase(endWord);
        unordered_set<string> s1 {beginWord};
        unordered_set<string> s2 {endWord};
        int ans = 0;
        while (!s1.empty()) {
            unordered_set<string> tmp;
            ans++;
            for (auto word : s1) {
                for (auto& ch : word) {
                    const char origin = ch;
                    for (int i = 0; i < 26; i++) {
                        ch = char('a' + i);
                        if (s2.find(word) != s2.end()) {
                            return ans + 1;
                        } else if (list.find(word) != list.end()) {
                            tmp.insert(word);
                            list.erase(word);
                        }
                    }
                    ch = origin;
                }
            }
            s1 = (tmp.size() < s2.size() ? tmp : s2);
            s2 = (tmp.size() < s2.size() ? s2 : tmp);
        }
        return 0;
    }
};

int main() {
    Solution so;
    vector<string> str {"ted","tex","red","tax","tad","den","rex","pee"};
    int ans = so.ladderLength("red", "tax", str);
    cout << ans << endl;
    return 0;
}