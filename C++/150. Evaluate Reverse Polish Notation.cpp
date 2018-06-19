#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int res = 0;
        for (auto str : tokens) {
            switch (str) {
                case "+" : {
                    int b = s.top();
                    s.pop();
                    int a = s.top();
                    s.pop();
                    s.push(a + b);
                    break;
                }
                case "-" : {
                    int b = s.top();
                    s.pop();
                    int a = s.top();
                    s.pop();
                    s.push(a - b);
                    break;
                }
                case "*" : {
                    int b = s.top();
                    s.pop();
                    int a = s.top();
                    s.pop();
                    s.push(a * b);
                    break;
                }
                case "/" : {
                    int b = s.top();
                    s.pop();
                    int a = s.top();
                    s.pop();
                    s.push(a / b);
                    break;
                }
                default : {
                    s.push(stoi(str));
                }
            }
            res = s.top();
        }
        return res;
    }
};