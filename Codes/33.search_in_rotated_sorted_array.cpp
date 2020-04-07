class Solution {
public:
    int search(vector<int>& nums, int target) {
        int size = nums.size();
        int mid = size;
        for (int i = 0; i < size - 1; ++i)
        {
            if (nums[i] > nums[i + 1]) {
                mid = i + 1;
                break;
            }
        }

        int res = 0;

        res = BinarySearch(nums, 0, mid - 1, target);
        return (res == -1 ? BinarySearch(nums, mid, size - 1, target) : res);
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
