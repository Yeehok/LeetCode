class Solution {
public:

    const int MaxInt = 2147483647;

    bool IsDigital(const char &c) {
        return c >= '0' && c <= '9';
    }

    bool IsValiedStart(const char &c) {
        return IsDigital(c) || c == '+' || c == '-';
    }

    bool AddValue(int &value, const char &c, bool &positive) {
        if (IsDigital(c)) {
            if (value > MaxInt / 10) {
                if (positive)
                {
                    value = MaxInt;
                }
                else
                {
                    value = -MaxInt - 1;
                    positive = true;
                }
                return false;
            }
            else if (value == MaxInt / 10
            && ((c >= '7' && positive) || (c >= '8' && !positive))) {
                if (positive)
                {
                    value = MaxInt;
                }
                else
                {
                    value = -MaxInt - 1;
                    positive = true;
                }
                return false;
            }
            value *= 10;
            value += static_cast<int> (c - '0');
            return true;
        }
        return false;
    }

    int myAtoi(string str) {
        const char *c_str = str.c_str();

        int size = static_cast<int> (str.size());
        bool has_start = false;
        bool positive = true;
        int value = 0;
        for (int i = 0; i < size; ++i) {
            if (!has_start) {
                if (IsValiedStart(c_str[i])) {
                    has_start = true;
                    if (c_str[i] == '-'
                        || c_str[i] == '+') {
                        positive = (c_str[i] != '-');
                        continue;
                    }
                } else if (c_str[i] != ' ') {
                    break;
                }
            }
            if (has_start) {
                if (!AddValue(value, c_str[i], positive)) {
                    break;
                }
            }
        }

        return (positive ? 1 : -1) * value;
    }
};
