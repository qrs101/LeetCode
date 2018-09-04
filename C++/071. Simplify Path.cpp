#include <iostream>
#include <stack>

class Solution {
public:
    std::string simplifyPath(std::string path) {
        std::stack<std::string> s;
        path = '/' + path + '/';
        for (int i = -1, j = 0; j < int(path.size()); j++) {
            if (path[j] != '/' && path[j - 1] == '/')
                i = j;
            if (path[j] == '/' && i != -1 && path[j - 1] != '/') {
                std::string tmp = path.substr(i, j - i);
                if (tmp == ".")
                    continue;
                else if (tmp == "..") {
                    if (!s.empty())
                        s.pop();
                } else
                    s.push(tmp);
            }
        }

        if (s.empty())
            return "/";
        std::string res = "";
        while (!s.empty()) {
            res = "/" + s.top() + res;
            s.pop();
        }
        return res;
    }
};