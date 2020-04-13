bool Cmp(const string &a, const string &b) {
    if (a.size() == b.size()) return a < b;
    return a.size() > b.size();
}

class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(), d.end(), &Cmp);

        bool found;
        int i;
        int s_size = s.size();
        for (auto &str : d) {
            found = true;
            i = 0;
            for (auto &c : str) {
                if (i == s_size) {
                    found = false;
                    break;
                }
                while (i < s_size) {
                    if (s[i++] == c) {
                        break;
                    }
                    if (i == s_size) {
                        found = false;
                    }
                }
            }
            if (found) {
                return str;
            }
        }
        return "";
    }
};
