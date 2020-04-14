class Solution {
public:
    vector<vector<int>> m_res;
    map<int, int> m_dumplicate;
    map<int, int> m_total;
    vector<int> m_single_res;
    set<vector<int>> m_ans_dump;

    void FindAns(vector<int>& nums) {
        if (m_single_res.size() == nums.size()) {
                m_res.emplace_back(m_single_res);
            return;
        }

        for (auto i : nums) {
            if (m_dumplicate[i] < m_total[i]) {
                ++m_dumplicate[i];
                m_single_res.emplace_back(i);
                if (m_ans_dump.find(m_single_res) == m_ans_dump.end()) {
                    m_ans_dump.insert(m_single_res);
                    FindAns(nums);
                }
                --m_dumplicate[i];
                m_single_res.pop_back();
            }
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        for (auto i : nums) {
            ++m_total[i];
        }

        sort(nums.begin(), nums.end());

        FindAns(nums);
        return m_res;
    }
};
