class Solution {
public:
    string addBinary(string a, string b) {
        int la = a.size() - 1;
        int lb = b.size() - 1;
        string c(la > lb ? la + 1 : lb + 1, '0');

        while (la >= 0 || lb >= 0) {
            if (la >= lb && lb >= 0) {
                c[la] = a[la] + b[lb] - '0';
            } else if (lb >= la && la >= 0) {
                c[lb] = a[la] + b[lb] - '0';
            } else if (lb < 0) {
                c[la] = a[la];
            } else if (la < 0) {
                c[lb] = b[lb];
            }
            if (la >= 0) --la;
            if (lb >= 0) --lb;
        }

        int size = c.size() - 1;
        while (size > 0) {
            c[size - 1] += (c[size] > '1' ? 1 : 0);
            if ((c[size] - '0') % 2 == 1) c[size] = '1';
            else c[size] = '0';
            --size;
        }
        if (!c.empty() && c[0] > '1') {
            c.insert(c.begin(), '1');
            if ((c[1] - '0') % 2 == 1) c[1] = '1';
            else c[1] = '0';
        }

        return c;
    }
};
