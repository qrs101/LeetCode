#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution {
public:
    bool check(vector<bool>& row, vector<bool>& column, vector<bool>& box, int num) {
        if (!row[num] && !column[num] && !box[num])
            return true;
        else
            return false;
    }

    void solveSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> row (9, vector<bool>(10, false));
        vector<vector<bool>> column (9, vector<bool>(10, false));
        vector<vector<bool>> box (9, vector<bool>(10, false));
        vector<vector<int>> a { {0,1,2}, {3,4,5}, {6,7,8} };
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                int k = a[i / 3][j / 3];
                if (board[i][j] == '.')
                    continue;
                int num = board[i][j] - '0';
                row[i][num] = true;
                column[j][num] = true;
                box[k][num] = true;
            }
        }

        stack<int> stack_i;    //行
        stack<int> stack_j;    //列
        stack<int> stack_num;  //数字
        int num = 1;
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] != '.')
                    continue;
                int k = a[i / 3][j / 3];
                for (; num <= 9; num++) {
                    if (check(row[i], column[j], box[k], num)) {
                        stack_num.push(num);
                        stack_i.push(i);
                        stack_j.push(j);
                        row[i][num] = true;
                        column[j][num] = true;
                        box[k][num] = true;
                        num = 1;
                        break;
                    }
                }
                if (num == 10) {
                    do {
                        i = stack_i.top();
                        j = stack_j.top();
                        num = stack_num.top();
                        stack_i.pop();
                        stack_j.pop();
                        stack_num.pop();
                        int k = a[i / 3][j / 3];
                        row[i][num] = false;
                        column[j][num] = false;
                        box[k][num] = false;
                        j--;
                        num++;
                    } while (num == 10);
                }
            }
        }
        while (!stack_num.empty()) {
            int i = stack_i.top();
            int j = stack_j.top();
            int num = stack_num.top();
            stack_i.pop();
            stack_j.pop();
            stack_num.pop();
            board[i][j] = char('0' + num);
        }
    }
};

int main() {
    vector<vector<char>> b {
        {'.',  '.',  '9',  '7',  '4',  '8',  '.',  '.',  '.'},
        {'7',  '.',  '.',  '.',  '.',  '.',  '.',  '.',  '.'},
        {'.',  '2',  '.',  '1',  '.',  '9',  '.',  '.',  '.'},
        {'.',  '.',  '7',  '.',  '.',  '.',  '2',  '4',  '.'},
        {'.',  '6',  '4',  '.',  '1',  '.',  '5',  '9',  '.'},
        {'.',  '9',  '8',  '.',  '.',  '.',  '3',  '.',  '.'},
        {'.',  '.',  '.',  '8',  '.',  '3',  '.',  '2',  '.'},
        {'.',  '.',  '.',  '.',  '.',  '.',  '.',  '.',  '6'},
        {'.',  '.',  '.',  '2',  '7',  '5',  '9',  '.',  '.'}
    };
    Solution so;
    so.solveSudoku(b);
    for (auto i : b) {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}