class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int> > anss;
		vector<int> ans;
		map<int, int> nums_exists;
		unsigned int size = static_cast<unsigned int> (nums.size());
		for (unsigned int i = 0; i < size; ++i)
		{
			++nums_exists[nums[i]];
		}
		sort(nums.begin(), nums.end());
		int mid = 0;
		int *a = NULL;
		int *b = NULL;
		for (unsigned int i = 0; i < size; ++i)
		{
			if (i > 0 && nums[i] == nums[i - 1]) continue;
			for (unsigned int j = i + 1; j < size; ++j)
			{
				if (j > i + 1 && nums[j] == nums[j - 1]) continue;
				mid = 0 - nums[i] - nums[j];
				if (mid < nums[j]) continue;
				map<int, int>::iterator it = nums_exists.find(mid);
				if (it != nums_exists.end())
				{
					a = &nums_exists[nums[i]];
					b = &nums_exists[nums[j]];
					--(*a);
					--(*b);
					if (it->second > 0)
					{
						ans.clear();
						ans.push_back(nums[i]);
						ans.push_back(nums[j]);
						ans.push_back(mid);
						anss.push_back(ans);
					}
					++(*a);
					++(*b);
				}
			}
		}
		return anss;
	}
};
