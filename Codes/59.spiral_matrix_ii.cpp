class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        const short dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        short cur_dir = 0;
        int sum = 0;
        vector<vector<int>> res;
        int x = 0, y = 0;
        for (int i = 0; i < n; ++i) {
            vector<int> line(n, 0);
            res.emplace_back(line);
        }

        int turn = 0;
        res[x][y] = ++sum;
        while (turn < 2) {
            if (x + dir[cur_dir][0] >= 0 && x + dir[cur_dir][0] < n
            && y + dir[cur_dir][1] >= 0 && y + dir[cur_dir][1] < n
            && res[x + dir[cur_dir][0]][y + dir[cur_dir][1]] == 0) {
                x += dir[cur_dir][0];
                y += dir[cur_dir][1];
                res[x][y] = ++sum;
                turn = 0;
            } else {
                ++turn;
                ++cur_dir;
                cur_dir %= 4;
            }
        }

        return res;
    }
};
