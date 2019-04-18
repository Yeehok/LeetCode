class Solution {
public:
    int romanToInt(string s) {
        map<string, int> roman_map;
        roman_map["M"] = 1000;
        roman_map["CM"] = 900;
        roman_map["D"] = 500;
        roman_map["CD"] = 400;
        roman_map["C"] = 100;
        roman_map["XC"] = 90;
        roman_map["L"] = 50;
        roman_map["XL"] = 40;
        roman_map["X"] = 10;
        roman_map["IX"] = 9;
        roman_map["V"] = 5;
        roman_map["IV"] = 4;
        roman_map["I"] = 1;
        int size = static_cast<int> (roman_map.size());

        int ans = 0;
        int str_size = static_cast<int> (s.size());
        string sub;
        for (int i = 0; i < str_size; i += static_cast<int> (sub.size())) {
            sub.clear();
            if (i < str_size - 1) {
                sub = s.substr(i, 2);
            }
            auto it = roman_map.find(sub);
            if (it == roman_map.end()) {
                sub = s.substr(i, 1);
                it = roman_map.find(sub);
            }


            if (it != roman_map.end()) {
                ans += it->second;
                continue;
            }
        }
        return ans;
    }
};
