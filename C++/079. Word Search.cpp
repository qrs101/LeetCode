#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word.size() == 0 || board.size() == 0 || board[0].size() == 0)
            return false;
        auto m = int(board.size()), n = int(board[0].size());
        vector<vector<bool>> seen(m, vector<bool>(n, false));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    seen[i][j] = true;
                    if (helper(board, seen, word, i, j))
                        return true;
                    seen[i][j] = false;
                }
            }
        }
        return false;
    }

    bool helper(vector<vector<char>> &board, vector<vector<bool>> &seen, string word, int i, int j) {
        if (word.size() == 1)
            return true;
        auto m = int(board.size()) - 1, n = int(board[0].size()) - 1;
        if (i - 1 >= 0 && board[i - 1][j] == word[1] && !seen[i - 1][j]) {
            seen[i - 1][j] = true;
            if (helper(board, seen, word.substr(1), i - 1, j))
                return true;
            seen[i - 1][j] = false;
        }
        if (i + 1 <= m && board[i + 1][j] == word[1] && !seen[i + 1][j]) {
            seen[i + 1][j] = true;
            if (helper(board, seen, word.substr(1), i + 1, j))
                return true;
            seen[i + 1][j] = false;
        }
        if (j - 1 >= 0 && board[i][j - 1] == word[1] && !seen[i][j - 1]) {
            seen[i][j - 1] = true;
            if (helper(board, seen, word.substr(1), i, j - 1))
                return true;
            seen[i][j - 1] = false;
        }
        if (j + 1 <= n && board[i][j + 1] == word[1] && !seen[i][j + 1]) {
            seen[i][j + 1] = true;
            if (helper(board, seen, word.substr(1), i, j + 1))
                return true;
            seen[i][j + 1] = false;
        }
        return false;
    }
};