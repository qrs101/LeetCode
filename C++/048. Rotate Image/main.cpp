#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        auto n = matrix.size();
        for (int i = 0, j = n - 1; i < j; i++, j--) {
            vector<int> tmp = matrix[i];
            matrix[i] = matrix[j];
            matrix[j] = tmp;
        }

        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int tmp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = tmp;
            }
        }
    }
};

int main() {
    vector<vector<int>> m {
            {1,2,3},
            {2,3,4},
            {3,4,5}
    };
    Solution so;
    so.rotate(m);
    for (auto i : m) {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}