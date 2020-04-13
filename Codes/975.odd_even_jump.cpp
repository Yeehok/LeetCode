class Solution {
public:
    enum ECurrentResultStatus {
        ECRS_Cant = 0,
        ECRS_OddCan = 1 << 0,
        ECRS_EvenCan = 1 << 1
    };

    bool SearchEnd(map<int, int> &cr, const vector<int> &arr, int cur, map<int, vector<int> > &sm, bool odd, bool force = false) {
        if (cur + 1 == arr.size()) {
            return true;
        }

        if (!force) {
            auto cr_it = cr.find(cur);
            if (cr_it != cr.end()) {
                return (odd && ((cr_it->second) & ECRS_OddCan))
                       || (!odd && ((cr_it->second) & ECRS_EvenCan));
            }
        }

        auto i = sm.find(arr[cur]);
        if (odd) {
            while (i != sm.end()) {
                for (int j : i->second) {
                    if (j > cur) {
                        if (SearchEnd(cr, arr, j, sm, !odd)) {
                            cr[j] |= ECRS_EvenCan;
                            return true;
                        } else {
                            cr[j] |= ECRS_Cant;
                            return false;
                        }
                    }
                }
                ++i;
            }
        } else {
            do {
                for (int j : i->second) {
                    if (j > cur) {
                        if (SearchEnd(cr, arr, j, sm, !odd)) {
                            cr[j] |= ECRS_OddCan;
                            return true;
                        } else {
                            cr[j] |= ECRS_Cant;
                            return false;
                        }
                    }
                }
            } while (i-- != sm.begin());
        }
        return false;
    }
    int oddEvenJumps(vector<int>& A) {
        int ans = 0;
        map<int, int> cur_res;
        map<int, vector<int> > search_map;

        int size = static_cast<int> (A.size());

        for (int i = 0; i < size; ++i) {
            search_map[A[i]].emplace_back(i);
        }

        for (int i = size - 1; i >= 0; --i) {
            if (SearchEnd(cur_res, A, i, search_map, true, true)) {
                cur_res[i] |= ECRS_OddCan;
                ++ans;
            }
            if (SearchEnd(cur_res, A, i, search_map, false, true)) {
                cur_res[i] |= ECRS_EvenCan;
            }
            cur_res[i] |= ECRS_Cant;
        }

        return ans;
    }
};
