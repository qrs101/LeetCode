#include <iostream>
#include <vector>
#include <map>

class Solution {
public:
    bool isValidSudoku(std::vector<std::vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            std::map<char, bool> haveNum {
                {'1',false}, {'2',false}, {'3',false}, {'4',false}, {'5',false},
                {'6',false}, {'7',false}, {'8',false}, {'9',false}
            };
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.')
                    continue;
                if (!haveNum[board[i][j]])
                    haveNum[board[i][j]] = true;
                else
                    return false;
            }
        }

        for (int j = 0; j < 9; j++) {
            std::map<char, bool> haveNum {
                    {'1',false}, {'2',false}, {'3',false}, {'4',false}, {'5',false},
                    {'6',false}, {'7',false}, {'8',false}, {'9',false}
            };
            for (int i = 0; i < 9; i++) {
                if (board[i][j] == '.')
                    continue;
                if (!haveNum[board[i][j]])
                    haveNum[board[i][j]] = true;
                else
                    return false;
            }
        }

        for (int I = 0; I < 3; I++) {
            for (int J = 0; J < 3; J++) {
                std::map<char, bool> haveNum {
                        {'1',false}, {'2',false}, {'3',false}, {'4',false}, {'5',false},
                        {'6',false}, {'7',false}, {'8',false}, {'9',false}
                };
                for (int i = 0; i < 3; i++) {
                    for (int j = 0; j < 3; j++) {
                        if (board[I * 3 + i][J * 3 + j] == '.')
                            continue;
                        if (!haveNum[board[I * 3 + i][J * 3 + j]])
                            haveNum[board[I * 3 + i][J * 3 + j]] = true;
                        else
                            return false;
                    }
                }
            }
        }

        return true;
    }
};