class Solution {
public:
	bool GuardPath(int &loc, int &path, const int &length, int &pre_fix)
	{
		if (loc - path < 0
			|| loc + pre_fix + path >= length)
		{
			return false;
		}
		return true;
	}

	void CalculatePalindromicSubstring(const char *str, const int &length, int &cur_loc, int &start, int &end, int &cur_length, int pre_fix = 0)
	{
		for (int j = 1; j < length; ++j)
		{
			if (GuardPath(cur_loc, j, length, pre_fix))
			{
				if (str[cur_loc - j] == str[cur_loc + pre_fix + j])
				{
					--start;
					cur_length += 2;
					++end;
				}
				else
				{
					break;
				}
			}
			else
			{
				break;
			}
		}
	}

	string longestPalindrome(string s) {
		const char *str = s.c_str();

		int length = static_cast<int> (s.size());
		int start = 0;
		int end = 0;
		int cur_length = 0;
		int max = -1;
		int max_start = 0;
		int max_end = 0;

		for (int i = 0; i < length; ++i)
		{
			start = i;
			end = i;
			cur_length = 1;

			CalculatePalindromicSubstring(str, length, i, start, end, cur_length);

			if (cur_length > max)
			{
				max = cur_length;
				max_start = start;
				max_end = end;
			}

			if (i + 1 < length && str[i] == str[i + 1])
			{
				start = i;
				end = i + 1;
				cur_length = 2;

				CalculatePalindromicSubstring(str, length, i, start, end, cur_length, 1);

				if (cur_length > max)
				{
					max = cur_length;
					max_start = start;
					max_end = end;
				}
			}
		}

		return s.substr(max_start, max_end - max_start + 1);
	}
};
