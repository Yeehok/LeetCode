class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int size = intervals.size();
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end(), [&](vector<int> a, vector<int> b) mutable {
            return a[0] < b[0];
        });
        for (int i = 0; i < size; ++i) {
            int &left = intervals[i][0];
            int &right = intervals[i][1];
            int source = i;
            for (int j = source + 1; j < size; ++j) {
                if (left <= intervals[j][0] && intervals[j][0] <= right) {
                    right = intervals[j][1] > right ? intervals[j][1] : right;
                    ++i;
                } else {
                    break;
                }
            }
            res.emplace_back(intervals[source]);
        }

        return res;
    }
};
