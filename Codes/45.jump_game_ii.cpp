class Solution {
public:

    int jump(vector<int>& nums) {
        int size = nums.size();
        vector<int> path(size);
        int dis = 0;
        int max = 0;
        int next_i = 0;

        for (int i = 0; i < size; ) {
            ++dis;
            max = 0;
            next_i = 0;
            for (int j = 1; j <= nums[i]; ++j) {
                if (i + j >= size) continue;

                if (path[i + j] != 0) continue;

                path[i + j] = dis;
                if (nums[i + j] - (nums[i] - j) > max) {
                    max = nums[i + j] - (nums[i] - j);
                    next_i = i + j;
                }
            }
            if (next_i == 0) break;
            i = next_i;
        }

        return path[size - 1];
    }
};
