class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if (nums.empty()) return 0;
        int max = nums[0];
        int sum = 0;
        for (auto i : nums) {
            if (sum + i > i) sum = sum + i;
            else sum = i;
            if (sum > max) max = sum;
        }
        return max;
    }
};
