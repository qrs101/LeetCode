#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        addParenthesis(res, "", n, 0);
        return res;
    }

    void addParenthesis(vector<string> &v, string str, int m, int n) {
        if (m == 0 && n == 0) {
            v.push_back(str);
            return;
        }
        if (n > 0)
            addParenthesis(v, str + ")", m, n - 1);
        if (m > 0)
            addParenthesis(v, str + "(", m - 1, n + 1);
    }
};

int main() {
    Solution so;
    vector<string> res = so.generateParenthesis(5);
    cout << res.size() << endl;
    for (auto i : res){
        cout << i << endl;
    }
}