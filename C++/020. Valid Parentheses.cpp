#include <iostream>
#include <stack>
#include <map>

class Solution {
public:
    bool isValid(std::string s) {
        std::stack<char> Stack;
        std::map<char, char> M {
            {'(', ')'}, {'[', ']'}, {'{', '}'}
        };
        for (int i = 0; i < int(s.size()); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                Stack.push(s[i]);
            else {
                if (Stack.empty() || s[i] != M[Stack.top()])
                    return false;
                Stack.pop();
            }
        }
        return Stack.empty();
    }
};