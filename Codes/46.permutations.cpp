class Solution {
public:
    vector<vector<int>> m_res;
    set<int> m_dumplicate;
    vector<int> m_single_res;

    void FindAns(vector<int>& nums) {
        if (m_single_res.size() == nums.size()) {
            m_res.emplace_back(m_single_res);
            return;
        }

        for (auto i : nums) {
            if (m_dumplicate.find(i) == m_dumplicate.end()) {
                m_dumplicate.insert(i);
                m_single_res.emplace_back(i);
                FindAns(nums);
                m_dumplicate.erase(i);
                m_single_res.pop_back();
            }
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        FindAns(nums);
        return m_res;
    }
};
