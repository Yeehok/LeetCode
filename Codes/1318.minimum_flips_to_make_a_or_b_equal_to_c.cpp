class Solution {
public:
    void ConvertBinary(int val, vector<int> &res) {
        while (val != 0) {
            res.emplace_back(val % 2);
            val /= 2;
        }
    }
    int minFlips(int a, int b, int c) {
        int count = 0;
        vector<int> ba;
        vector<int> bb;
        vector<int> bc;
        ConvertBinary(a, ba);
        ConvertBinary(b, bb);
        ConvertBinary(c, bc);
        int basz = ba.size();
        int bbsz = bb.size();
        int bcsz = bc.size();

        for (int i = 0, j = 0, k = 0; i < basz || j < bbsz || k < bcsz; ++i, ++j, ++k) {
            if (i < basz && j < bbsz && k < bcsz) {
                if (bc[k] && (!ba[i] && !bb[j])) ++count;
                if (!bc[k]) {
                    if (ba[i]) ++count;
                    if (bb[j]) ++count;
                }
            } else if (i < basz && k < bcsz) {
                if (bc[k] && !ba[i]) ++count;
                if (!bc[k] && ba[i]) ++count;
            } else if (j < bbsz && k < bcsz) {
                if (bc[k] && !bb[j]) ++count;
                if (!bc[k] && bb[j]) ++count;
            } else if (k < bcsz) {
                if (bc[k]) ++count;
            } else {
                if (i < basz) {
                    if (ba[i]) ++count;
                }
                if (j < bbsz) {
                    if (bb[j]) ++count;
                }
            }
        }
        return count;
    }
};
