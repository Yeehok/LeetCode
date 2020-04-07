class Solution {
public:
	bool canJump(vector<int>& nums) {
		int size = static_cast<int> (nums.size());
		vector<bool> can_arrive(size);
		can_arrive[0] = true;
		for (int i = 1; i < size; ++i)
        {
			for (int j = i - 1; j >= 0; --j)
            {
				if (can_arrive[j] && nums[j] + j >= i)
				{
					can_arrive[i] = true;
					break;
				}
            }
        }
		return can_arrive[size - 1];
	}
};
