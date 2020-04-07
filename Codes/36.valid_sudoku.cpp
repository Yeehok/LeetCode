class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; ++i) {
            if (!IsValidColumn(board, i)
            || !IsValidRow(board, i)) return false;
        }

        for (int x = 0; x < 9; x += 3) {
            for (int y = 0; y < 9; y += 3) {
                if (!IsValidNine(board, x, y)) return false;
            }
        }
        return true;
    }

    bool IsValidColumn(vector<vector<char>>& board, int row) {
        vector<bool> st(9);
        for (int i = 0; i < 9; ++i) {
            if (board[row][i] == '.') continue;
            if (st[board[row][i] - '0']) return false;
            st[board[row][i] - '0'] = true;
        }
        return true;
    }

    bool IsValidRow(vector<vector<char>>& board, int column) {
        vector<bool> st(9);
        for (int i = 0; i < 9; ++i) {
            if (board[i][column] == '.') continue;
            if (st[board[i][column] - '0']) return false;
            st[board[i][column] - '0'] = true;
        }
        return true;
    }

    bool IsValidNine(vector<vector<char>>& board, int x, int y) {
        vector<bool> st(9);
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[x + i][y + j] == '.') continue;
                if (st[board[x + i][y + j] - '0']) return false;
                st[board[x + i][y + j] - '0'] = true;
            }
        }
        return true;
    }
};
