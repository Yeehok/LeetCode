class Solution {
public:
    string intToRoman(int num) {
        vector<pair<int, string> > roman_map;
        roman_map.emplace_back(1000, "M");
        roman_map.emplace_back(900, "CM");
        roman_map.emplace_back(500, "D");
        roman_map.emplace_back(400, "CD");
        roman_map.emplace_back(100, "C");
        roman_map.emplace_back(90, "XC");
        roman_map.emplace_back(50, "L");
        roman_map.emplace_back(40, "XL");
        roman_map.emplace_back(10, "X");
        roman_map.emplace_back(9, "IX");
        roman_map.emplace_back(5, "V");
        roman_map.emplace_back(4, "IV");
        roman_map.emplace_back(1, "I");
        int size = static_cast<int> (roman_map.size());

        string ans;
        while (num > 0) {
            for (int i = 0; i < size; ++i) {
                if (num / roman_map[i].first != 0) {
                    num -= roman_map[i].first;
                    ans += roman_map[i].second;
                    break;
                }
            }
        }
        return ans;
    }
};
