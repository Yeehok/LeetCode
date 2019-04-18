class Solution {
public:
    bool IsMatch(const char &a, const char &b) {
        if (a == b) return true;
        return (a == '.' || b == '.');
    }
    
    bool TrySolve(const char *s, const char *p, int i, int j, int resume, const char &last, const int &s_len, const int &p_len) {
        if (i >= s_len && j >= p_len) return true;
        bool s_flag = true;
        bool p_flag = true;
        if (i >= s_len) s_flag = false;
        if (j >= p_len) return false;

        if (p[j] == '*') {
            if (p_flag && TrySolve(s, p, resume, j + 1, resume, last, s_len, p_len)) {
                return true;
            }
            for (int idx = resume; last != '\0' && s_flag && p_flag && idx < s_len && IsMatch(s[idx], last); ++idx) {
                if (TrySolve(s, p, idx + 1, j + 1, idx + 1, last, s_len, p_len)) {
                    return true;
                }
            }
        }

        if (s_flag && p_flag && IsMatch(s[i], p[j])) {
            if (TrySolve(s, p, i + 1, j + 1, i + 1, p[j], s_len, p_len)) {
                return true;
            }
        }
        if ((j < p_len - 1 && p[j + 1] != '*')
        || j == p_len - 1) {
            return false;
        }
        return TrySolve(s, p, i, j + 1, i, '\0', s_len, p_len);
    }

    bool isMatch(string s, string p) {
        const char *s_str = s.c_str();
        const char *p_str = p.c_str();

        int s_len = static_cast<int> (s.size());
        int p_len = static_cast<int> (p.size());

        return TrySolve(s_str, p_str, 0, 0, 0, '\0', s_len, p_len);
    }
};