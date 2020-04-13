class Solution {
public:
    void Swap(int &a, int &b) {
        int c = a;
        a = b;
        b = c;
    }
    vector<int> replaceElements(vector<int>& arr) {
        if (arr.empty()) return arr;
        int size = arr.size();
        int max = arr[size - 1];
        for (int i = size - 1; i >= 0; --i) {
            if (arr[i] > max) {
                Swap(arr[i], max);
            }
            else {
                arr[i] = max;
            }
        }

        arr[size - 1] = -1;

        return arr;
    }
};
