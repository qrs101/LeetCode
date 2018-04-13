#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> ans;
        unordered_set<string> list (wordList.begin(), wordList.end());
        if (list.find(endWord) == list.end())
            return ans;
        list.erase(beginWord);
        list.erase(endWord);
        unordered_set<string> s1 {beginWord};
        unordered_set<string> s2 {endWord};
        unordered_map<string, unordered_set<string>> path;
        path.insert(unordered_map<string, unordered_set<string>>::value_type(beginWord, unordered_set<string>()));
        for (auto i : list)
            path.insert(unordered_map<string, unordered_set<string>>::value_type(i, unordered_set<string>()));
        bool toEnd = true, found = false;
        while (!found && !s1.empty()) {
            unordered_set<string> tmp;
            for (auto Word : s1) {
                string word = Word;
                for (auto& ch : word) {
                    const char origin = ch;
                    for (int i = 0; i < 26; i++) {
                        ch = char('a' + i);
                        if (s2.find(word) != s2.end())
                            found = true;
                        else if (list.find(word) != list.end())
                            tmp.insert(word);
                        else
                            continue;

                        if (toEnd)
                            path[Word].insert(word);
                        else
                            path[word].insert(Word);
                    }
                    ch = origin;
                }
            }
            for (auto i : tmp)
                list.erase(i);
            s1 = (tmp.size() < s2.size() ? tmp : s2);
            s2 = (tmp.size() < s2.size() ? s2 : tmp);
            toEnd = (tmp.size() < s2.size() ? toEnd : !toEnd);
        }
        if (!found)
            return ans;
        ans = getPath(beginWord, endWord, path);
        return ans;
    }

    vector<vector<string>> getPath(string begin, string end, unordered_map<string, unordered_set<string>>& path) {
        vector<vector<string>> ans;
        if (path[begin].size() == 0)
            return ans;
        if (path[begin].find(end) != path[begin].end()) {
            vector<string> tmp {begin, end};
            ans.push_back(tmp);
            return ans;
        }
        for (auto word : path[begin]) {
            vector<vector<string>> tmp = getPath(word, end, path);
            if (tmp.size() == 0)
                continue;
            for (auto& p : tmp) {
                p.insert(p.begin(), begin);
                ans.push_back(p);
            }
        }
        return ans;
    }
};

int main() {
    Solution so;
    vector<string> str {"ted","tex","red","tax","tad","den","rex","pee"};
    vector<vector<string>> ans = so.findLadders("red", "tax", str);

    for (auto i : ans) {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }

}