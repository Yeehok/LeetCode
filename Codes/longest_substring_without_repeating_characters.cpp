class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		const char *str = s.c_str();
		int size = static_cast<int> (s.size());

		std::map<char, int> anti_repeat;

		int res = 0;
		int cur = 0;

		for (int i = 0; i < size; ++i)
		{
			std::map<char, int>::iterator it = anti_repeat.find(*str);
			if (it == anti_repeat.end())
			{
				anti_repeat[*str] = i;
				++cur;
			}
			else
			{
				if (cur > res)
				{
					res = cur;
				}
				cur = cur + 1 < i - it->second ? cur + 1 : i - it->second;
				it->second = i;
			}

			++str;
		}

		return cur > res ? cur : res;
	}
};
