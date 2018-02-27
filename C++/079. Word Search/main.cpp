#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (word.size() == 0)
            return true;
        if (board.size() == 0 || board[0].size() == 0)
            return false;
        vector<vector<bool>> tag (board.size(), vector<bool>(board[0].size(), false));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] == word[0]) {
                    tag[i][j] = true;
                    //cout << i << " " << j << endl;
                    if (exist_at_location(board, tag, word, i, j))
                        return true;
                    tag[i][j] = false;
                }
            }
        }
        return false;
    }

    bool exist_at_location(vector<vector<char>>& board, vector<vector<bool>>& tag, string word, int i, int j) {
        if (word.size() == 1)
            return true;
        if (i - 1 >= 0 && board[i - 1][j] == word[1] && tag[i - 1][j] == false) {
            tag[i - 1][j] = true;
            if (exist_at_location(board, tag, word.substr(1), i - 1, j))
                return true;
            tag[i - 1][j] = false;
        }
        if (i + 1 < board.size() && board[i + 1][j] == word[1] && tag[i + 1][j] == false) {
            tag[i + 1][j] = true;
            if (exist_at_location(board, tag, word.substr(1), i + 1, j))
                return true;
            tag[i + 1][j] = false;
        }
        if (j - 1 >= 0 && board[i][j - 1] == word[1] && tag[i][j - 1] == false) {
            tag[i][j - 1] = true;
            if (exist_at_location(board, tag, word.substr(1), i, j - 1))
                return true;
            tag[i][j - 1] = false;
        }
        if (j + 1 < board[0].size() && board[i][j + 1] == word[1] && tag[i][j + 1] == false) {
            tag[i][j + 1] = true;
            if (exist_at_location(board, tag, word.substr(1), i, j + 1))
                return true;
            tag[i][j + 1] = false;
        }
        return false;
    }
};

int main() {
    Solution so;
    vector<vector<char>> board = {
            {'A','B','C','E'},
            {'S','F','C','S'},
            {'A','D','E','E'}
    };
    string word = "ABCCED";
    bool ans = so.exist(board, word);
    cout << ans << endl;
    return 0;
}