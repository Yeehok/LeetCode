class Solution {
public:
    void swapInt(int &a, int &b) {
        if (&a == &b) return;
        a += b;
        b += a;
        a = b - a;
        b -= (2 * a);
    }
    void nextPermutation(vector<int>& nums) {
        int size = nums.size();
        for (int i = size - 2; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) {
                for (int j = size - 1; j >= 0; --j) {
                    if (nums[j] > nums[i]) {
                        swapInt(nums[i], nums[j]);
                        for (int k = i + 1, l = size - 1; k < l; ++k, --l) {
                            swapInt(nums[k], nums[l]);
                        }
                        break;
                    }
                }
                return;
            }
        }
        for (int i = 0, j = size - 1; i < j; ++i, --j) {
            swapInt(nums[i], nums[j]);
        }
    }
};
