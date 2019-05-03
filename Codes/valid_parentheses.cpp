class Solution {
public:
    bool isValid(string s) {
        auto size = s.size();

        stack<char> stk;

        for (int i = 0; i < size; ++i) {
            if (s[i] == ')' || s[i] == ']' || s[i] =='}') {
                if (stk.empty()
                || (s[i] == ')'
                && stk.top() != '(')
                || (s[i] == ']'
                && stk.top() != '[')
                || (s[i] == '}'
                && stk.top() != '{')) {
                    return false;
                }
                else {
                    stk.pop();
                }
            }
            else {
                stk.push(s[i]);
            }
        }
        return stk.empty();
    }
};
