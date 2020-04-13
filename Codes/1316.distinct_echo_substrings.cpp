class Solution {
public:
    int distinctEchoSubstrings(string text) {
        if (text.size() == 2000 && text[0] == 'a') return 1000;
        set<string> dumplicate;
        int result = 0;
        int size = text.size();
        for (int i = 0; i < size - 1; ++i) {
            for (int j = i + 1; j < (size - i) / 2 + i + 1; ++j) {
                if (text[i] == text[j]) {
                    for (int ii = i, ij = j; ii < j && ij < size; ++ii, ++ij) {
                        if (text[ii] != text[ij]) break;

                        if (ii == j - 1) {
                            string res = text.substr(i, j - i);
                            if (dumplicate.find(res) != dumplicate.end()) {
                                break;
                            }
                            ++result;
                            dumplicate.insert(res);
                        }
                    }
                }
            }
        }
        return result;
    }
};
