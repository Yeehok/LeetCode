class Solution {
public:
    int divide(int dividend, int divisor) {
        long long res = (long long)dividend / (long long)divisor;

        if (res > ((1 << 31) - 1)) res = ((1 << 31) - 1);

        return int(res);
    }
};
