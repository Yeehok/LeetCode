class Solution {
public:
    string dfs_stack;
    void CalculateCombination(const string &digits, const int &size, map<char, string> &d2c, int idx, vector<string> &res) {
        if (idx >= size) {
            res.emplace_back(dfs_stack);
            return;
        }
        for (const auto &i : d2c[digits[idx]]) {
            dfs_stack.push_back(i);
            CalculateCombination(digits, size, d2c, idx + 1, res);
            dfs_stack.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        map<char, string> digit_to_char;
        digit_to_char['2'] = "abc";
        digit_to_char['3'] = "def";
        digit_to_char['4'] = "ghi";
        digit_to_char['5'] = "jkl";
        digit_to_char['6'] = "mno";
        digit_to_char['7'] = "pqrs";
        digit_to_char['8'] = "tuv";
        digit_to_char['9'] = "wxyz";

        vector<string> res;
        auto size = digits.size();

        if (size > 0) {
            CalculateCombination(digits, size, digit_to_char, 0, res);
        }
        
        return res;
    }
};
