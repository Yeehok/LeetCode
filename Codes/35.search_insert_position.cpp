class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        int r = nums.size() - 1;
        int mid = 0;
        int res = nums.size();
        while (l <= r) {
            mid = (l + r) / 2;
            if (nums[mid] == target) return mid;

            if (nums[mid] > target) {
                res = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return res;
    }
};
