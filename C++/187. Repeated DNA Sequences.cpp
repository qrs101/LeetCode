#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        map<string, int> m;
        for (int i = 0; i <= int(s.size()) - 10; i++) {
            string str = s.substr(i, 10);
            if (m.find(str) == m.end()) {
                m.insert(map<string, int>::value_type(str, 1));
            } else if (m[str] == 1) {
                res.push_back(str);
                m[str]++;
            }
        }
        return res;
    }
};

int main() {
    Solution so;
    string s = "";
    vector<string> res = so.findRepeatedDnaSequences(s);
    for (auto str : res)
        cout << str << endl;
    return 0;
}