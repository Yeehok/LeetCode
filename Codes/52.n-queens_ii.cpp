class Solution {
public:
    set<int> idx;
    int res = 0;
    vector<string> mp;
    void FindSolution(int &n) {
        if (mp.size() == n) {
            ++res;
            return;
        }

        int size = mp.size();
        int x;
        int y;
        bool cont;
        for (int i = 0; i < n; ++i) {
            if (idx.find(i) == idx.end()) {
                x = size;
                y = i;
                cont = false;
                while (x > 0 && y > 0) {
                    if (mp[--x][--y] == 'Q') cont = true;
                }
                x = size;
                y = i;
                while (x > 0 && y < n - 1) {
                    if (mp[--x][++y] == 'Q') cont = true;
                }
                if (cont) continue;
                mp.emplace_back("");
                for (int j = 0; j < n; ++j) {
                    mp[size] += (i == j ? 'Q' : '.');
                }
                idx.insert(i);
                FindSolution(n);
                idx.erase(i);
                mp.pop_back();
            }
        }
    }
    int totalNQueens(int n) {
        FindSolution(n);
        return res;
    }
};
