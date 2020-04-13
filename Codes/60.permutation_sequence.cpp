class Solution {
public:
    void NextPermutation(string &nums) {
        int size = nums.size();
        for (int i = size - 2; i >= 0; --i) {
            if (nums[i] < nums[i + 1]) {
                for (int j = size - 1; j >= 0; --j) {
                    if (nums[j] > nums[i]) {
                        swap(nums[i], nums[j]);
                        for (int k = i + 1, l = size - 1; k < l; ++k, --l) {
                            swap(nums[k], nums[l]);
                        }
                        break;
                    }
                }
                return;
            }
        }
        for (int i = 0, j = size - 1; i < j; ++i, --j) {
            swap(nums[i], nums[j]);
        }
    }

    string getPermutation(int n, int k) {
        string nums;
        for (int i = 1; i <= n; ++i) {
            nums.push_back(i + '0');
        }

        for (int i = 1; i < k; ++i) {
            NextPermutation(nums);
        }
        return nums;
    }
};
