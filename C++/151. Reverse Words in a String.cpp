#include<iostream>
using namespace std;

class Solution {
public:
    void reverseWords(string &s) {
        int i = 0, j = 0;
        auto n = int(s.size());
        string s_ = "";
        while (n != 0) {
            for (i = 0; i < n && s[i] == ' '; i++);
            for (j = i; j < n && s[j] != ' '; j++);
			if (i < n) {
                s_ = s.substr(i, j - i) + s_;
                s_ = " " + s_;
			    i = j;
			}
            n -= j;
            s.erase(0, j);
        }
        for (i = 0; i < s_.size() && s_[i] == ' '; i++);
        s_.erase(0, i);
		s = s_;
    }
};

int main() {
    string s = "abc def gg ";
    Solution so = new Solution();
    so.reverseWords(s);
    cout << s << endl;
    return 0;
}
