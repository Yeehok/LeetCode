class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {

		int len = static_cast<unsigned int> (nums.size());

		std::set<int> nums_set;
		std::vector<int> ans_indices;
		std::map<int, int> num_index;

		for (int i = len - 1; i >= 0; --i)
		{
			nums_set.insert(nums[i]);
			num_index[nums[i]] = i;
		}

		for (int i = 0; i < len; ++i)
		{
			int oi = num_index[target - nums[i]];
			if (oi != i
				&& nums_set.find(target - nums[i]) != nums_set.end())
			{
				ans_indices.push_back(i);
				ans_indices.push_back(oi);
				break;
			}
		}

		return ans_indices;
	}
};