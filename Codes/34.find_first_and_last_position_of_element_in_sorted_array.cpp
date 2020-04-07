class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int size = nums.size();
        int res = BinarySearch(nums, 0, size - 1, target);
        vector<int> res_vec({res, res});
        if (res == -1) return res_vec;
        for (int i = res; i >= 0; --i) {
            if (nums[i] == target) {
                res_vec[0] = i;
            }
        }
        for (int i = res; i < size; ++i) {
            if (nums[i] == target) {
                res_vec[1] = i;
            }
        }
        return res_vec;
    }

    int BinarySearch(vector<int>& nums, int l, int r, int value) {
        int mid;
        while (l <= r) {
            mid = (l + r) / 2;
            if (nums[mid] < value) {
                l = mid + 1;
            }
            else if (nums[mid] > value) {
                r = mid - 1;
            }
            else {
                return (mid);
            }
        }
        return -1;
    }
};
