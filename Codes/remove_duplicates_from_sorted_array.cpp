class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        auto size = nums.size();

        int res = size;
        int cur = 1;

        for (int i = 1; i < size; ++i) {
            if (nums[i] == nums[i - 1]) {
                --res;
            }
            else {
                nums[cur++] = nums[i];
            }
        }
        return res;
    }
};
