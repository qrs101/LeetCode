#include <iostream>
#include <vector>
#include <stack>
#include <map>

class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board, int i, int j, char filling) {
        for (int k = 0; k < 9; k++) {
            if (k != j && board[i][k] == filling)
                return false;
        }

        for (int k = 0; k < 9; k++) {
            if (k != i && board[k][j] == filling)
                return false;
        }

        for (int I = i / 3 * 3; I < i / 3 * 3 + 3; I++) {
            for (int J = j / 3 * 3; J < j / 3 * 3 + 3; J++) {
                if ((I != i || J != j) && board[I][J] == filling)
                    return false;
            }
        }

        return true;
    }

    void solveSudoku(std::vector<std::vector<char>>& board) {
        std::stack<int> row, col;
        char filling = '1';
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.')
                    continue;
                for (; filling <= '9'; filling++) {
                    board[i][j] = filling;
                    if (isValidSudoku(board, i, j, filling))
                        break;
                }
                if (filling > '9') {
                    board[i][j] = '.';
                    if (!row.empty()) {
                        i = row.top();
                        j = col.top();
                        row.pop();
                        col.pop();
                        filling = char(board[i][j] + 1);
                        board[i][j] = '.';
                        j--;
                    } else {
                        return;
                    }
                } else {
                    row.push(i);
                    col.push(j);
                    filling = '1';
                }
            }
        }
    }
};
/*
int main() {
    std::vector<std::vector<char>> b {
            {'5', '3', '4', '.', '7', '.', '.', '.', '.'},
            {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
            {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
            {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
            {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
            {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
            {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
            {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
            {'.', '.', '.', '.', '8', '.', '.', '7', '9'},
    };
    Solution so;
    so.solveSudoku(b);
    for (auto i : b) {
        for (auto j : i)
            std::cout << j << " ";
        std::cout << std::endl;
    }
    return 0;
}
*/