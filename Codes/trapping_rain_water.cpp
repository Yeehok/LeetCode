class Solution {
public:
    int trap(vector<int>& height) {
        int n = static_cast<int> (height.size());

        int ans = 0;
        int inter;
        for (int i = 1; i < n; ++i) {
            if (height[i] <= height[i - 1]) continue;

            inter = height[i] - height[i - 1];

            for (int k = height[i] - inter; k <= height[i]; ++k) {
                for (int j = i - 1; j >= 0; --j) {
                    if (height[j] >= k) {
                        ans += (i - j - 1);
                        break;
                    }
                }
            }
        }
        return ans;
    }
};
