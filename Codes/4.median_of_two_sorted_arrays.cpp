class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int size1 = static_cast<int> (nums1.size());
		int size2 = static_cast<int> (nums2.size());
		bool is_odd = (((size1 + size2) % 2) == 1);
		unsigned int pos = static_cast<unsigned int>(size1 + size2) >> 1;

		vector<int> nums;

		int cur1 = 0;
		int cur2 = 0;
		while (true)
		{
			if (cur1 < size1
				&& cur2 < size2)
			{
				if (nums1[cur1] < nums2[cur2])
				{
					nums.push_back(nums1[cur1]);
					++cur1;
				}
				else
				{
					nums.push_back(nums2[cur2]);
					++cur2;
				}
			}
			else if (cur1 < size1)
			{
				nums.push_back(nums1[cur1]);
				++cur1;
			}
			else if (cur2 < size2)
			{
				nums.push_back(nums2[cur2]);
				++cur2;
			}
			else break;
		}

		if (is_odd)
		{
			return nums[pos];
		}
		else
		{
			return static_cast<double> (nums[pos] + nums[pos - 1]) / 2.0;
		}
	}
};
