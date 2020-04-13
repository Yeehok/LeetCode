class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int l = 1;
        int r = 0;
        for (auto i : nums) {
            if (i > r) r = i;
        }
        r /= (threshold / nums.size());
        ++r;
        int mid = 0;
        int res = 0;

        while (l <= r) {
            mid = (l + r) / 2;
            if (Satisfied(nums, mid, threshold)) {
                res = mid;
                r = mid - 1;
            }
            else l = mid + 1;
        }
        return res;
    }

    bool Satisfied(vector<int>& nums, int value, int &threshold) {
        int sum = 0;
        for (auto i : nums) {
            sum += ((i / value) + (i % value == 0 ? 0 : 1));

            if (sum > threshold) return false;
        }
        return true;
    }
};
