class Solution {
public:
	double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
		int size1 = static_cast<int> (nums1.size());
		int size2 = static_cast<int> (nums2.size());
		bool is_odd = (((size1 + size2) % 2) == 1);
		unsigned int pos = static_cast<unsigned int>(size1 + size2) >> 1;

		if (pos == 0)
		{
			return static_cast<double> (size1 == 0 ? nums2[0] : nums1[0]);
		}
		if (size1 == 0)
		{
			if (is_odd)
			{
				return nums2[pos];
			}
			else
			{
				return static_cast<double> (nums2[pos] + nums2[pos - 1]) / 2.0;
			}
		}
		if (size2 == 0)
		{
			if (is_odd)
			{
				return nums1[pos];
			}
			else
			{
				return static_cast<double> (nums1[pos] + nums1[pos - 1]) / 2.0;
			}
		}

		int cur1 = 0;
		int cur2 = 0;

		while (true)
		{
			if (cur1 < size1
				&& cur2 < size2)
			{
				if (nums1[cur1] < nums2[cur2])
				{
					++cur1;
				}
				else
				{
					++cur2;
				}
			}
			else if (cur1 < size1)
			{
				++cur1;
			}
			else if (cur2 < size2)
			{
				++cur2;
			}

			if (cur1 + cur2 == static_cast<int> (pos))
			{
				if (is_odd)
				{
					if (cur1 < size1
						&& cur2 < size2)
					{
						return nums1[cur1] < nums2[cur2] ? nums1[cur1] : nums2[cur2];
					}
					else if (cur1 < size1)
					{
						return nums1[cur1];
					}
					else if (cur2 < size2)
					{
						return nums2[cur2];
					}
				}
				else
				{
					if (cur1 < size1
						&& cur2 < size2)
					{
						if (cur1 != 0
							&& cur2 != 0)
						{
							return static_cast<double> ((nums1[cur1] < nums2[cur2] ? nums1[cur1] : nums2[cur2])
								+ (nums1[cur1 - 1] > nums2[cur2 - 1] ? nums1[cur1 - 1] : nums2[cur2 - 1])) / 2.0;
						}
						else if (cur1 == 0)
						{
							return static_cast<double> ((nums1[cur1] < nums2[cur2] ? nums1[cur1] : nums2[cur2])
								+ nums2[cur2 - 1]) / 2.0;
						}
						else if (cur2 == 0)
						{
							return static_cast<double> ((nums1[cur1] < nums2[cur2] ? nums1[cur1] : nums2[cur2])
								+ nums1[cur1 - 1]) / 2.0;
						}
					}
					else if (cur1 < size1)
					{
						return static_cast<double> ((nums2[cur2 - 1] > nums1[cur1 - 1] ? nums2[cur2 - 1] : nums1[cur1 - 1]) + nums1[cur1]) / 2.0;
					}
					else if (cur2 < size2)
					{
						return static_cast<double> ((nums1[cur1 - 1] > nums2[cur2 - 1] ? nums1[cur1 - 1] : nums2[cur2 - 1]) + nums2[cur2]) / 2.0;
					}
				}
			}
		}
		return 0.0;
	}
};
