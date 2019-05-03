class Solution {
public:
    typedef unsigned long long int64;
    string longestCommonPrefix(vector<string>& strs) {
        int64 size = static_cast<int64> (strs.size());
        if (size == 0) return "";
        int64 idx = 0;
        bool brk = false;
        char last = 0;
        while (true) {
            if (brk) break;
            for (int64 i = 0; i < size; ++i) {
                if (strs[i].size() > idx) {
                    if (i == 0) {
                        last = strs[i][idx];
                    }
                    if (strs[i][idx] != last) {
                        --idx;
                        brk = true;
                        break;
                    }
                } else {
                    --idx;
                    brk = true;
                    break;
                }
            }
            ++idx;
        }
        return size > 0 ? strs[0].substr(0, idx) : "";
    }
};
