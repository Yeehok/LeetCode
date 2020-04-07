bool CMP(vector<int> &a, vector<int> &b) {
    return a[0] - a[1] < b[0] - b[1];
}

class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        int size_out = static_cast<int> (costs.size()) / 2;
        int ans = 0;

        sort(costs.begin(), costs.end(), &CMP);
        for (int i = 0; i < size_out * 2; ++i) {
            if (i < size_out) {
                ans += costs[i][0];
            }
            else {
                ans += costs[i][1];
            }
        }

        return ans;
    }
};
