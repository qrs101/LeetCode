#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        map<string, int> M;
        vector<string> ans;
        for (int i = 0; i < int(cpdomains.size()); i++) {
            int p = partition(cpdomains[i], ' ');
            int num = stoi(cpdomains[i].substr(0, p));
            string str = cpdomains[i].substr(p + 1);
            do {
                if (M.find(str) == M.end())
                    M.insert(map<string, int>::value_type(str, num));
                else
                    M[str] += num;
                p = partition(str, '.');
                str = str.substr(p + 1);
            } while (str != "");
        }
        for (auto i : M)
            ans.push_back(to_string(i.second) + " " + i.first);
        return ans;
    }

    int partition(string& s, char c) {
        for (int i = 0; i < int(s.size()); i++) {
            if (s[i] == c)
                return i;
        }
        return int(s.size()) - 1;
    }
};

int main() {
    vector<string> s {"900 google.mail.com", "50 yahoo.com", "1 intel.mail.com", "5 wiki.org"};
    Solution so;
    vector<string> ans = so.subdomainVisits(s);
    for (auto i : ans)
        cout << i << endl;
}