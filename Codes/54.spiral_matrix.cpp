class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        const short dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        short cur_dir = 0;
        vector<int> res;
        int x_min = 0;
        int x_max = int(matrix.size()) - 1;
        if (matrix.empty()) return res;
        int y_min = 0;
        int y_max = int(matrix[0].size()) - 1;
        if (matrix[0].empty()) return res;
        int x = 0;
        int y = 0;
        res.emplace_back(matrix[0][0]);
        int last_res = 0;
        int turn = 0;
        while (true) {
            if (last_res != res.size()) turn = 0;
            if (turn > 1) break;
            last_res = res.size();
            switch (cur_dir) {
                case 0:
                    if (y < y_max) {
                        res.emplace_back(matrix[x][++y]);
                    } else {
                        ++x_min;
                        ++cur_dir;
                        ++turn;
                    }
                    break;
                case 1:
                    if (x < x_max) {
                        res.emplace_back(matrix[++x][y]);
                    } else {
                        --y_max;
                        ++cur_dir;
                        ++turn;
                    }
                    break;
                case 2:
                    if (y > y_min) {
                        res.emplace_back(matrix[x][--y]);
                    } else {
                        --x_max;
                        ++cur_dir;
                        ++turn;
                    }
                    break;
                case 3:
                    if (x > x_min) {
                        res.emplace_back(matrix[--x][y]);
                    } else {
                        ++y_min;
                        cur_dir = 0;
                        ++turn;
                    }
                    break;
                default:
                    break;
            }
        }

        return res;
    }
};
