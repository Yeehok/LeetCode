class Solution {
public:
	int reverse(int x) {
		bool is_positive = true;
		long long source = x;
		if (x < 0)
		{
			is_positive = false;
			source = -source;
		}

		long long ans = 0;

		while (source != 0)
		{
			ans *= 10;
			ans += source % 10;
			source /= 10;
		}

		ans = (ans > ((1 << 31) - 1) ? 0 : ans);

		if (!is_positive) ans = -ans;

		return ans;
	}
};
