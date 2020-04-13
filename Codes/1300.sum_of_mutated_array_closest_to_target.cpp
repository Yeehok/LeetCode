class Solution {
public:
    int Satisfied(const vector<int> &arr, const int target, const int value) {
        int sum = 0;
        for (auto i : arr) {
            sum += i > target ? target : i;
        }
        return sum;
    }
    int findBestValue(vector<int>& arr, int target) {
        int l = 0;
        int r = target;
        int mid = 0;
        int value = 0;
        int small = 0;
        int large = 0;
        while (l <= r) {
            mid = (l + r) / 2;
            if ((value = Satisfied(arr, mid, target)) < target) {
                small = value;
                l = mid + 1;
            }
            else if ((value = Satisfied(arr, mid, target)) > target) {
                large = value;
                r = mid - 1;
            }
            else {
                return (mid);
            }
        }
        if (abs(small - target) <= abs(large - target)) return l - 1;
        return r + 1;
    }
};
