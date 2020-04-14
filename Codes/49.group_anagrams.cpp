class Solution {
public:
    map<string, int> dumplicate;
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        vector<string> temp;
        for (auto i : strs) {
            string cp = i;
            sort(cp.begin(), cp.end());
            auto it = dumplicate.find(cp);
            if (it == dumplicate.end()) {
                res.push_back(temp);
                dumplicate.insert(make_pair(cp, res.size() - 1));
                it = dumplicate.find(cp);
            }
            res[it->second].push_back(i);
        }

        return res;
    }
};
