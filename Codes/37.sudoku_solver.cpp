class Solution {
public:
    bool m_record = false;

    void solveSudoku(vector<vector<char>>& board) {
        DepthFirstSearch(board, 0, 0);
    }

    void DepthFirstSearch(vector<vector<char>>& board, int x, int y) {
        if (m_record || (x == 8 && y == 8 && board[x][y] != '.')) {
            m_record = true;
            return;
        }

        if (board[x][y] == '.') {
            vector<bool> invalid(10);
            GetValidNumber(board, x, y, invalid);

            for (int i = 1; i < 10 && !m_record; ++i) {
                if (!invalid[i]) {
                    board[x][y] = i + '0';
                    if (x == 8 && y == 8) {
                        m_record = true;
                        return;
                    }
                    SearchNext(board, x, y);
                    if (m_record) return;
                    board[x][y] = '.';
                }
            }
        }
        else {
            SearchNext(board, x, y);
        }
    }

    void SearchNext(vector<vector<char>>& board, int x, int y) {
        if (x < 8) {
            DepthFirstSearch(board, x + 1, y);
        }
        else if (y < 8) {
            DepthFirstSearch(board, 0, y + 1);
        }
    }

    void GetValidNumber(const vector<vector<char>> &board, int x, int y, vector<bool> &invalid) {
        for (int i = 0; i < 9; ++i) {
            if (board[x][i] != '.') {
                invalid[board[x][i] - '0'] = true;
            }
            if (board[i][y] != '.') {
                invalid[board[i][y] - '0'] = true;
            }
        }

        int startx = 3;
        int starty = 3;
        GetStart(startx, x);
        GetStart(starty, y);

        for (int i = startx; i < startx + 3; ++i) {
            for (int j = starty; j < starty + 3; ++j) {
                if (board[i][j] == '.') continue;

                invalid[board[i][j] - '0'] = true;
            }
        }
    }

    void GetStart(int &start, int value) {
        if (value - 4 <= -2) start = 0;
        else if (value - 4 >= 2) start = 6;
    }
};
