#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        auto num_of_words = int(words.size());
        vector<string> ans;
        int length = 0, i = 0;
        for (int j = 0; j < num_of_words; j++) {
            length += int(words[j].size());
            if (length + j - i == maxWidth) {
                string str = words[i];
                for (int k = i + 1; k <= j; k++)
                    str += " " + words[k];
                ans.push_back(str);
                i = j + 1;
                length = 0;
            } else if (length + j - i > maxWidth) {
                length -= int(words[j].size());
                string str = words[i];
                if (j == i + 1) {
                    string space(maxWidth - length, ' ');
                    str += space;
                } else {
                    int s = (maxWidth - length) / (j - i - 1);
                    int r = (maxWidth - length) % (j - i - 1);
                    for (int k = i + 1; k < j; k++, r--) {
                        string space(s, ' ');
                        if (r > 0)
                            space += " ";
                        str += space;
                        str += words[k];
                    }
                }
                ans.push_back(str);
                i = j;
                length = 0;
                j--;
            } else if (j == num_of_words - 1) {
                string str = words[i];
                for (int k = i + 1; k <= j; k++)
                    str += " " + words[k];
                string space(maxWidth - str.size(), ' ');
                str += space;
                ans.push_back(str);
            }
        }
        return ans;
    }
};

int main() {
    vector<string> words {""};
    Solution so;
    vector<string> ans = so.fullJustify(words, 0);
    //cout << ans.size() << endl;
    for (auto i : ans)
        cout << i << "#"<< endl;
    return 0;
}