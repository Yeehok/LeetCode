class Solution {
public:
    struct Node {
        int x;
        int y;
        Node(int px = 0, int py = 0)
        : x(px)
        , y(py) {}
    };
    int minPathSum(vector<vector<int>>& grid) {
        if (grid.empty()
        || grid[0].empty()) {
            return 0;
        }
        vector<vector<int>> dis(grid.size(), vector<int>(grid[0].size(), -1));
        int m = grid.size();
        int n = grid[0].size();
        queue<Node> que;
        que.push(Node());
        Node orgin;
        dis[0][0] = grid[0][0];
        while (!que.empty()) {
            orgin = que.front();
            que.pop();
            if (orgin.x < m - 1
            && (dis[orgin.x + 1][orgin.y] == -1 || grid[orgin.x + 1][orgin.y] + dis[orgin.x][orgin.y] < dis[orgin.x + 1][orgin.y])) {
                que.push(Node(orgin.x + 1, orgin.y));
                dis[orgin.x + 1][orgin.y] = grid[orgin.x + 1][orgin.y] + dis[orgin.x][orgin.y];
            }
            if (orgin.y < n - 1
                && (dis[orgin.x][orgin.y + 1] == -1 || grid[orgin.x][orgin.y + 1] + dis[orgin.x][orgin.y] < dis[orgin.x][orgin.y + 1])) {
                que.push(Node(orgin.x, orgin.y + 1));
                dis[orgin.x][orgin.y + 1] = grid[orgin.x][orgin.y + 1] + dis[orgin.x][orgin.y];
            }
        }

        return dis[m - 1][n - 1];
    }
};
