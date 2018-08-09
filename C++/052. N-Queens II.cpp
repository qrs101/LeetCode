#include <iostream>
#include <vector>
#include <stack>

class Solution {
public:
    int totalNQueens(int n) {
        std::stack<int> row, col;
        int res = 0;
        std::vector<std::string> board(n, std::string(n, '.'));
        for (int i = 0, j = 0; i < n; i++) {
            for (; j < n; j++) {
                if (check(board, i, j)) {
                    board[i][j] = 'Q';
                    row.push(i);
                    col.push(j);
                    j = 0;
                    break;
                }
            }
            if (row.empty())
                break;
            if (j == n) {
                i = row.top(), j = col.top();
                row.pop();
                col.pop();
                board[i][j] = '.';
                i--;
                j++;
            }
            if (i == n - 1 && j != n) {
                res++;
                i = row.top(), j = col.top();
                row.pop();
                col.pop();
                board[i][j] = '.';
                i--;
                j++;
            }
        }
        return res;
    }

    bool check(std::vector<std::string>& board, int i, int j) {
        int n = int(board.size());

        for (int k = 0; k < i; k++)
            if (board[k][j] == 'Q')
                return false;

        for (int k1 = i, k2 = j; k1 >= 0 && k2 >= 0; k1--, k2--)
            if (board[k1][k2] == 'Q')
                return false;

        for (int k1 = i, k2 = j; k1 >= 0 && k2 < n; k1--, k2++)
            if (board[k1][k2] == 'Q')
                return false;

        return true;
    }
};