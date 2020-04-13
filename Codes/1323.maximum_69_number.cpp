class Solution {
public:
    int maximum69Number (int num) {
        int len = 1000000000;
        int op = num;
        while (len != 0 && op / len != 6) {
            op %= len;
            len /= 10;
        }
        if (len >= 0) {
            num += 3 * len;
        }
        return num;
    }
};
