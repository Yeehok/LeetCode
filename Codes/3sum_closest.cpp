class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        auto size = nums.size();
        int sum;
        int mini = 2147483640;
        int res;
        for (int i = 0; i < size; ++i) {
            for (int j = i + 1; j < size; ++j) {
                for (int k = j + 1; k < size; ++k) {
                    sum = nums[i] + nums[j] + nums[k];
                    if (abs(sum - target) < mini) {
                        mini = abs(sum - target);
                        if (mini == 0) {
                            return sum;
                        }
                        res = sum;
                    }
                }
            }
        }
        return res;
    }
};
