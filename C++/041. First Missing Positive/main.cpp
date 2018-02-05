#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        vector<int> v(nums);
        v.insert(v.begin(), 0);
        for (int i = 1; i < v.size(); i++) {
            if (v[i] <= 0 || v[i] >= v.size())
                continue;
            else if (v[i] != i) {
                int j = v[i];
                if (v[j] != j) {
                    int tmp = v[i];
                    v[i] = v[j];
                    v[j] = tmp;
                    i--;
                }
            }
        }
        for (int i = 1; i < v.size(); i++)
            if (v[i] != i)
                return i;
        return v.size();
    }
};

int main() {
    vector<int> a {-1,4,2,1,9,10};
    Solution so;
    int ans = so.firstMissingPositive(a);
    cout << ans << endl;
    return 0;
}