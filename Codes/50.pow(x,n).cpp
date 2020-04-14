class Solution {
public:
    double myPow(double x, int n) {
        double pow = 0;
        double result = 0;

        if (n == 0) {
            result = 1;
        } else {
            pow = myPow(x, n / 2);
            if (n % 2 == -1) {
                result = pow * pow / x;
            }
            if (n % 2 == 0) {
                result = pow * pow;
            }
            if (n % 2 == +1) {
                result = pow * pow * x;
            }
        }
        return result;
    }
};
