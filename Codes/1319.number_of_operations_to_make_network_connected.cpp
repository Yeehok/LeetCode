class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() + 1 < n) return -1;

        vector<int> connection(n, 0);

        int idx = 1;

        for (const auto &i : connections) {
            if (connection[i[0]] == 0 && connection[i[1]] == 0) {
                connection[i[0]] = idx;
                connection[i[1]] = idx;
                ++idx;
            } else if (connection[i[0]] == 0) {
                connection[i[0]] = connection[i[1]];
            } else if (connection[i[1]] == 0) {
                connection[i[1]] = connection[i[0]];
            } else {
                int tar = connection[i[0]];
                for (auto &j : connection) {
                    if (j == tar) {
                        j = connection[i[1]];
                    }
                }
            }
        }

        sort(connection.begin(), connection.end());
        int res = 0;
        int last = 0;
        for (const auto &i : connection) {
            if (i == 0) ++res;
            if (last != 0 && i != last) ++res;
            last = i;
        }

        return res;
    }
};
