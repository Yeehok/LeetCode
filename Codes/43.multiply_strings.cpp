class Solution {
public:
    string multiply(string num1, string num2) {
        int size1 = num1.size();
        int size2 = num2.size();
        vector<int> res(size1 + size2, 0);
        string res_str;
        int temp = 0;
        for (int i = 0; i < size1; ++i) {
            for (int j = 0; j < size2; ++j) {
                temp = (num1[size1 - i - 1] - '0') * (num2[size2 - j - 1] - '0');
                res[i + j] += temp;
                res[i + j + 1] += res[i + j] / 10;
                res[i + j] %= 10;
            }
        }
        reverse(res.begin(), res.end());
        for (int i = 0; i < size1 + size2; ++i) {
            if (res[i] != 0) {
                for (; i < size1 + size2; ++i) {
                    res_str.push_back(res[i] + '0');
                }
            }
        }

        return res_str.empty() ? "0" : res_str;
    }
};
