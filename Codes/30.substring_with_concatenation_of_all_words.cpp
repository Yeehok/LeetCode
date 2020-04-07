class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> ans;
        map<string, short> mapping;
        map<short, short> source;
        vector<pair<short, int>> s_for_int;

        if (words.empty()) return ans;

        int size = words.size();
        int single_size = words[0].size();

        int ai_i = 0;
        for (const auto & i : words) {
            auto it = mapping.find(i);
            if (it != mapping.end()) {
                ++source[it->second];
            }
            else {
                mapping[i] = ++ai_i;
                ++source[ai_i];
            }
        }

        s_for_int.emplace_back(make_pair(0, 0));
        string subs;
        size_t s_size = s.size();
        for (size_t i = 0; i < s_size; ++i) {
            subs = s.substr(i, single_size);

            auto res = mapping.find(subs);
            if (res == mapping.end()) {
                if (s_for_int.rbegin()->first == 0
                || i - s_for_int.rbegin()->second < single_size) continue;
                s_for_int.emplace_back(make_pair(0, i));
            }
            else {
                s_for_int.emplace_back(make_pair(res->second, i));
            }
        }

        bool found;
        map<short, short> duplicate;
        int count;
        size_t i_size = s_for_int.size();
        int last_idx;
        for (size_t i = 1; i < i_size; ++i) {
            found = true;
            duplicate.clear();
            count = 0;
            last_idx = -1;
            for (int j = i; j < i_size; ++j) {
                if (last_idx != -1 && (s_for_int[j].second - last_idx != single_size)) continue;
                auto res_d = duplicate.find(s_for_int[j].first);
                auto res_s = source.find(s_for_int[j].first);
                if ((res_d == duplicate.end() && res_s != source.end())
                    || (res_d != duplicate.end() && res_s != source.end() && res_d->second < res_s->second)) {
                    if (res_d == duplicate.end()) ++duplicate[s_for_int[j].first];
                    else ++res_d->second;
                    ++count;
                    last_idx = s_for_int[j].second;
                }
                else {
                    found = false;
                    break;
                }

                if (count == size) break;
            }

            if (found && count == size)
            {
                ans.emplace_back(s_for_int[i].second);
            }
        }

        return ans;
    }
};
