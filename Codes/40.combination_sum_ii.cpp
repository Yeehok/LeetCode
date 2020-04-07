class Solution {
public:
    vector<int> path;
    set<vector<int>> dup;
    int sum;

    void dfs(vector<vector<int>> &res, const int &target, vector<int>& candidates, int begin) {
        if (sum > target) return;
        if (sum == target) {
            if (dup.find(path) != dup.end()) return;
            res.push_back(path);
            dup.insert(path);
            return;
        }

        int size = candidates.size();
        for (int i = begin; i < size; ++i) {
            //if (i > 0 && candidates[i - 1] == candidates[i]) continue;
            path.push_back(candidates[i]);
            sum += candidates[i];
            dfs(res, target, candidates, i + 1);
            path.pop_back();
            sum -= candidates[i];
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> res;

        sort(candidates.begin(), candidates.end());

        sum = 0;
        dfs(res, target, candidates, 0);

        return res;
    }
};
