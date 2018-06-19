#include <iostream>
using namespace std;

class Solution {
public:
    string reverseVowels(string s) {
        int i = 0, j = int(s.size()) - 1;
        while (i < j) {
            while (i < j && !isVowels(s[i]))
                i++;
            while (i < j && !isVowels(s[j]))
                j--;
            if (i < j) {
                char c = s[i];
                s[i] = s[j];
                s[j] = c;
            }
            i++;
            j--;
        }
        return s;
    }

    bool isVowels(char c) {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
            return true;
        else if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U')
            return true;
        else
            return false;
    }
};