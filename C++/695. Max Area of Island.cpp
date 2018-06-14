#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int ans = 0;
        auto m = int(grid.size());
        if (m == 0)
            return ans;
        auto n = int(grid[0].size());
        if (n == 0)
            return ans;
        for (auto& array : grid) {
            array.insert(array.begin(), 0);
            array.push_back(0);
        }
        grid.insert(grid.begin(), vector<int>(n + 2, 0));
        grid.emplace_back(n + 2, 0);
        queue<int> R;
        queue<int> C;
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (grid[i][j] == 0)
                    continue;
                int tmp = 0;
                R.push(i);
                C.push(j);
                while (!R.empty()) {
                    int r = R.front();
                    int c = C.front();
                    R.pop();
                    C.pop();
                    if (grid[r][c] == 0)
                        continue;
                    grid[r][c] = 0;
                    tmp++;
                    if (grid[r - 1][c] == 1) {
                        R.push(r - 1);
                        C.push(c);
                    }
                    if (grid[r + 1][c] == 1) {
                        R.push(r + 1);
                        C.push(c);
                    }
                    if (grid[r][c - 1] == 1) {
                        R.push(r);
                        C.push(c - 1);
                    }
                    if (grid[r][c + 1] == 1) {
                        R.push(r);
                        C.push(c + 1);
                    }
                }
                cout << tmp << endl;
                if (ans < tmp)
                    ans = tmp;
            }
        }
        return ans;
    }
};