class Solution {
public:
    vector<int> path;
    set<vector<int>> duplicated;
    int sum;

    void dfs(vector<vector<int>> &res, const int &target, vector<int>& candidates) {
        if (sum > target) return;
        if (sum == target) {
            vector<int> path_copy = path;
            sort(path_copy.begin(), path_copy.end());
            if (duplicated.find(path_copy) == duplicated.end()) {
                res.push_back(path_copy);
                duplicated.insert(path_copy);
            }
            return;
        }

        for (auto i : candidates) {
            path.push_back(i);
            sum += i;
            dfs(res, target, candidates);
            path.pop_back();
            sum -= i;
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;

        sum = 0;
        dfs(res, target, candidates);

        return res;
    }
};
