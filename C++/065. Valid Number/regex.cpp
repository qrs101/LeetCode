#include <iostream>
#include <regex>
using namespace std;

class Solution {
public:
    bool isNumber(string s) {
        string str("\\s*[+-]?(\\d+\\.?\\d*|\\d*\\.\\d+)([Ee][+-]?\\d+)?\\s*");
        regex match(str);
        return regex_match(s, match);
    }
};

int main() {
    string s = "  001423e+23";
    regex match("\\s*[+-]?(\\d+\\.?\\d*|\\d*\\.\\d+)([Ee][+-]?\\d+)?\\s*");
    //regex match("\\d+");
    if (regex_match(s, match))
        cout << "匹配成功" << endl;
    else
        cout << "匹配失败" << endl;
    return 0;
}