bool Cmp(const string &a, const string &b) {
    if (a.size() == b.size()) return a < b;
    return a.size() > b.size();
}

class Solution {
public:
    string longestWord(vector<string>& words) {
        set<string> st;
        for (auto &str : words) {
            st.insert(str);
        }

        sort(words.begin(), words.end(), &Cmp);

        int size;
        bool found;
        for (auto &str : words) {
            found = true;
            size = str.size();
            for (int i = 1; i < size; ++i) {
                if (st.find(str.substr(0, i)) == st.end()) {
                    found = false;
                    break;
                }
            }
            if (found) return str;
        }

        return "";
    }
};
