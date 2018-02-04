#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<vector<bool>> row (9, vector<bool>(10, false));
        vector<vector<bool>> column (9, vector<bool>(10, false));
        vector<vector<bool>> box (9, vector<bool>(10, false));
        vector<vector<int>> a {
                {0,1,2},
                {3,4,5},
                {6,7,8}
        };
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                int k = a[i/3][j/3];
                char tmp = board[i][j];
                if (tmp == '.')
                    continue;
                int num = tmp - '0';
                if (row[i][num])
                    return false;
                row[i][num] = true;
                if (column[j][num])
                    return false;
                column[j][num] = true;
                if (box[k][num])
                    return false;
                box[k][num] = true;
                //cout << i << " " << j << " " << k << endl;
            }
        }
        return true;
    }
};

int main() {
    vector<vector<char>> b {
        {'.',  '.',  '5',  '.',  '.',  '.',  '.',  '.',  '6'},
        {'.',  '.',  '.',  '.',  '1',  '4',  '.',  '.',  '.'},
        {'.',  '.',  '.',  '.',  '.',  '.',  '.',  '.',  '.'},
        {'.',  '.',  '.',  '.',  '.',  '9',  '2',  '.',  '.'},
        {'5',  '.',  '.',  '.',  '.',  '2',  '.',  '.',  '.'},
        {'.',  '.',  '.',  '.',  '.',  '.',  '.',  '3',  '.'},
        {'.',  '.',  '.',  '5',  '4',  '.',  '.',  '.',  '.'},
        {'3',  '.',  '.',  '.',  '.',  '.',  '4',  '2',  '.'},
        {'.',  '.',  '.',  '2',  '7',  '.',  '6',  '.',  '.'}
    };
    Solution so;
    bool ans = so.isValidSudoku(b);
    cout << ans << endl;
    return 0;
}