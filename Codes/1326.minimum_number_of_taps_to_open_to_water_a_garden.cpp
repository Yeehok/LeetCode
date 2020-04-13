class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<pair<int, int>> range;
        int loc = 0;
        for (auto i : ranges) {
            range.emplace_back(make_pair(loc - i, loc + i));
            ++loc;
        }

        sort(range.begin(), range.end(), [](pair<int, int> &a, pair<int, int> &b) {
            return a.first < b.first;
        });

        int left = 0;
        int res = 0;
        bool found;
        vector<pair<int, int>>::iterator now;
        while (true) {
            found = false;
            if (range.empty()) return -1;
            auto i = range.begin();
            now = range.end();
            for (; i != range.end()
                    ; ++i) {
                if (left < i->first) break;
                if (left <= i->second && (now == range.end() || i->second > now->second)) {
                    now = i;
                    found = true;
                }
            }
            if (!found) return -1;
            ++res;
            left = now->second;
            if (left >= n) break;
            range.erase(now);
        }

        return res;
    }
};
