class Solution {
public:
	bool Satisfied(const char &a, const char &b)
	{
		if (a == '0')
			return false;
		int v = 10 * (a - '0') + b - '0';
		return v <= 26 && v > 0;
	}

	int numDecodings(string s) {
		const char *str = s.c_str();
		unsigned int len = static_cast<unsigned int> (s.size());

		if (len == 0 || str[0] == '0')
		{
			return 0;
		}

		for (unsigned int i = 0; i < len - 1; ++i)
		{
			if (str[i] == '0'
				&& str[i + 1] == '0')
			{
				return 0;
			}
		}

		int *dp = new int[len];

		for (unsigned int i = 0; i < len; ++i) dp[i] = 0;

		dp[0] = 1;
		dp[1] = (Satisfied(str[0], str[1]) && str[1] != '0') ? 2 : Satisfied(str[0], str[1]) || str[1] != '0' ? 1 : 0;

		for (unsigned int i = 2; i < len; ++i)
		{
			if (str[i] == '0' && Satisfied(str[i - 1], str[i])) { dp[i] = dp[i - 2]; continue; }
			else if (str[i] == '0') continue;
			dp[i] = Satisfied(str[i - 1], str[i]) ? dp[i - 1] + dp[i - 2] : dp[i - 1];
		}

		return dp[len - 1];
	}
};
