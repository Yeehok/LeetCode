class Solution {
public:
	string convert(string s, int numRows) {
		int distance = (numRows - 1) * 2;
		int len = static_cast<int> (s.size());

		if (distance == 0)
		{
			return s;
		}
		string ans;
		int j;
		int fix;

		for (int i = 0; i < numRows; ++i)
		{
			j = i;
			fix = ((distance == 2 * i) ? 0 : (-2 * i));
			while (j < len)
			{
				ans += s.at(j);
				j += (distance + fix);
				if (fix != 0)
				{
					fix = -(distance + fix);
				}
			}
		}

		return ans;
	}
};
