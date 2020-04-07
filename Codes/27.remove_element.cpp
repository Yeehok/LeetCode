class Solution {
public:
    bool Swap(int &a, int &b) {
        if (&a == &b) return false;
        a += b;
        b += a;
        a = b - a;
        b -= (2 * a);
        return true;
    }

    int removeElement(vector<int> &nums, int val) {
        int size = nums.size();

        int rei = size - 1;
        int res = size;
        for (int i = 0; i < size; ++i) {
            if (nums[i] == val) {
                for (; rei > i; --rei) {
                    if (nums[rei] != val) {
                        Swap(nums[i], nums[rei]);
                        ++res;
                        break;
                    }
                }
                --res;
            }
        }
        return res;
    }
};
