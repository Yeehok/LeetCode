class Solution {
public:
    int firstMissingPositive(vector<int> &nums) {
        set<int> exist_array;

        for (auto i : nums) {
            if (i > 0) {
                exist_array.insert(i);
            }
        }

        int s = 1;
        for (auto i : exist_array) {
            if (s != i) return s;
            ++s;
        }
        return s;
    }
};
