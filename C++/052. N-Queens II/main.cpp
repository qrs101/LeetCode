#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    int totalNQueens(int n) {
        stack<int> row;
        stack<int> column;
        int ans = 0;
        vector<string> board(n, string(n, '.'));
        int j = 0;
        for (int i = 0; i < n; i++) {
            for (; j < n; j++) {
                if (check(board, i, j)) {
                    board[i][j] = 'Q';
                    row.push(i);
                    column.push(j);
                    j = 0;
                    break;
                }
            }
            if (j == n) {
                if (i == 0)
                    break;
                i = row.top();
                j = column.top();
                row.pop();
                column.pop();
                board[i][j] = '.';
                i--;
                j++;
                continue;
            }
            if (i == n - 1 && j != n) {
                ans++;
                i = row.top();
                j = column.top();
                row.pop();
                column.pop();
                board[i][j] = '.';
                i--;
                j++;
            }
        }
        return ans;
    }

    bool check(vector<string>& board, int row, int column) {
        int n = board.size();

        for (int i = 0; i < row; i++)
            if (board[i][column] == 'Q')
                return false;

        for (int i = row, j = column; i >= 0 && j >= 0; i--, j--)
            if (board[i][j] == 'Q')
                return false;

        for (int i = row, j = column; i >= 0 && j < n; i--, j++)
            if (board[i][j] == 'Q')
                return false;

        return true;
    }
};

int main() {
    Solution so;
    int ans = so.totalNQueens(5);
    cout << ans << endl;
    return 0;
}