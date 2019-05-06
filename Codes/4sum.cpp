class Solution {
public:
    vector<vector<int>> fourSum(vector<int> &nums, int target) {
        auto size = nums.size();
        map<int, int> appear;

        vector<vector<int>> res;
        vector<int> ans;

        for (int i = 0; i < size; ++i) {
            ++appear[nums[i]];
        }
        sort(nums.begin(), nums.end());

        int mid;
        for (int i = 0; i < size; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            --appear[nums[i]];
            for (int j = i + 1; j < size; ++j) {
                if (j > i + 1 && nums[j] == nums[j - 1]) continue;
                --appear[nums[j]];
                for (int k = j + 1; k < size; ++k) {
                    if (k > j + 1 && nums[k] == nums[k - 1]) continue;
                    mid = target - nums[i] - nums[j] - nums[k];
                    if (mid < nums[k]) continue;
                    --appear[nums[k]];
                    auto it = appear.find(mid);
                    if (it != appear.end()
                    && it->second > 0) {
                        ans.clear();
                        ans.emplace_back(nums[i]);
                        ans.emplace_back(nums[j]);
                        ans.emplace_back(nums[k]);
                        ans.emplace_back(mid);
                        res.emplace_back(ans);
                    }
                    ++appear[nums[k]];
                }
                ++appear[nums[j]];
            }
            ++appear[nums[i]];
        }

        return res;
    }
};
