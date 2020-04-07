class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = static_cast<int> (height.size());

        int min;
        int ans = 0;
        int tmp;
        for (int i = 0; i < n; ++i) {
            for (int j = n - 1; j > i; --j) {
                min = height[i] < height[j] ? height[i] : height[j];
                tmp = min * (j - i);
                if (tmp > ans) ans = tmp;
            }
        }
        return ans;
    }
};
