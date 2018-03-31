#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        auto m = int(board.size());
        if (m == 0)
            return;
        auto n = int(board[0].size());
        if (n == 0)
            return;
        vector<vector<int>> N;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'X')
                    continue;
                bool tag = false;
                queue<vector<int>> Q;
                Q.push(vector<int>{i, j});
                vector<vector<int>> S;
                while (!Q.empty()) {
                    vector<int> q = Q.front();
                    Q.pop();
                    int r = q[0];
                    int c = q[1];
                    if (r == 0 || r == m - 1 || c == 0 || c == n - 1)
                        tag = true;
                    if (board[r][c] == 'X')
                        continue;
                    S.push_back(vector<int>{r, c});
                    board[r][c] = 'X';
                    if (r > 0 && board[r - 1][c] == 'O')
                        Q.push(vector<int>{r - 1, c});
                    if (r < m - 1 && board[r + 1][c] == 'O')
                        Q.push(vector<int>{r + 1, c});
                    if (c > 0 && board[r][c - 1] == 'O')
                        Q.push(vector<int>{r, c - 1});
                    if (c < n - 1 && board[r][c + 1] == 'O')
                        Q.push(vector<int>{r, c + 1});
                }
                if (tag)
                    N.insert(N.end(), S.begin(), S.end());
            }
        }
        for (auto i : N) {
            board[i[0]][i[1]] = 'O';
        }
    }
};