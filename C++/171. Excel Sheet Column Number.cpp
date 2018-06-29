#include<iostream>
#include<map>
using namespace std;

class Solution {
public:
    int titleToNumber(string s) {
        map<char, int> m;
		char ch;
		int i;
		for (ch = 'A', i = 1; i <= 26; i++, ch++) {
			m.insert(map<char, int>::value_type(ch, i));
		}

		auto n = int(s.size());
		int res = 0;
		for (int i = n - 1, j = 1; i >= 0; i--, j *= 26) {
			res += m[s[i]] * j;
		}
		return res;
    }
};

int main() {
	Solution so;
	int res = so.titleToNumber("AAB");
	cout << res << endl;
	return 0;
}
