#include <iostream>
using namespace std;

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int start_v1 = 0, start_v2 = 0;
        int end_v1 = -1, end_v2 = -1;
        int len_v1 = int(version1.size()), len_v2 = int(version2.size());
        while (end_v1 < len_v1 && end_v2 < len_v2) {
            for (end_v1++, start_v1 = end_v1; end_v1 < len_v1 && version1[end_v1] != '.'; end_v1++);
            for (end_v2++, start_v2 = end_v2; end_v2 < len_v2 && version2[end_v2] != '.'; end_v2++);
            string str_v1 = version1.substr(start_v1, end_v1 - start_v1);
            string str_v2 = version2.substr(start_v2, end_v2 - start_v2);
            int v1 = stoi(str_v1), v2 = stoi(str_v2);
            if (v1 > v2)
                return 1;
            else if (v1 < v2)
                return -1;
        }
        if (end_v1 == len_v1 && end_v2 == len_v2)
            return 0;
        if (end_v1 < len_v1) {
            for (; end_v1 < len_v1; end_v1++)
                if (version1[end_v1] != '0' && version1[end_v1] != '.')
                    return 1;
            return 0;
        } else {
            for (; end_v2 < len_v2; end_v2++)
                if (version2[end_v2] != '0' && version2[end_v2] != '.')
                    return -1;
            return 0;
        }
    }
};

int main() {
    string str1 = "1.0.1";
    string str2 = "1.0";
    Solution so;
    int res = so.compareVersion(str1, str2);
    cout << res << endl;
    return 0;
}