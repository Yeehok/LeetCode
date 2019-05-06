class Solution {
public:
    string sres;
    int l_in_res;
    int r_in_res;

    void SearchResult(vector<string> &res, const int lleft, const int rleft) {
        if (lleft == 0 && rleft == 0) {
            res.emplace_back(sres);
            return;
        }
        if (lleft > 0) {
            sres.push_back('(');
            ++l_in_res;
            SearchResult(res, lleft - 1, rleft);
            --l_in_res;
            sres.pop_back();
        }

        if (rleft > 0
        && r_in_res < l_in_res) {
            sres.push_back(')');
            ++r_in_res;
            SearchResult(res, lleft, rleft - 1);
            --r_in_res;
            sres.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;

        l_in_res = 0;
        r_in_res = 0;
        SearchResult(res, n, n);

        return res;
    }
};
