class Solution {
public:
    string countAndSay(int n) {
        string last = "1";
        string res = last;
        int size;
        char lstc;
        int count;
        for (int i = 2; i <= n; ++i) {
            last = res;
            size = last.size();
            lstc = last[0];
            count = 0;
            res.clear();

            for (int j = 0; j < size; ++j) {
                stringstream ss;
                if (j == size - 1) {
                    if (last[j] == lstc) {
                        ss << (count + 1);
                        res += ss.str();
                        res += lstc;
                    }
                    else {
                        ss << count;
                        res += ss.str();
                        res += lstc;
                        res += '1';
                        res += last[j];
                    }
                }
                else {
                    if (last[j] == lstc) ++count;
                    else {
                        ss << count;
                        res += ss.str();
                        res += lstc;
                        lstc = last[j];
                        count = 1;
                    }
                }

            }
        }

        return res;
    }
};
