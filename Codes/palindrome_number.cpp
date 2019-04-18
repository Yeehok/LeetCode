class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        char *str_x = new char[11];
        int len = -1;
        while (x > 0)
        {
            str_x[++len] = x % 10;
            x /= 10;
        }
        int i = 0;
        while (i < len)
        {
            if (str_x[i] != str_x[len]) return false;
            ++i;
            --len;
        }

        return true;
    }
};
