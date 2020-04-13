class Solution {
public:
    bool NoZeroNum(int val) {
        if (val == 0) return false;
        while (val != 0) {
            if (val % 10 == 0) return false;
            val /= 10;
        }
        return true;
    }
    vector<int> getNoZeroIntegers(int n) {
        vector<int> res;

        for (int i = 1; i < n; ++i) {
            if (NoZeroNum(i) && NoZeroNum(n - i)) {
                if (i < n - i) {
                    res.emplace_back(i);
                }
                res.emplace_back(n - i);
                if (i >= n - i) {
                    res.emplace_back(i);
                }
                break;
            }
        }
        return res;
    }
};
