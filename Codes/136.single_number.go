func singleNumber(nums []int) int {
	sort.Ints(nums)

	l := len(nums)
	for i := 0; i < l; i+=2 {
		if i == l - 1 || nums[i] != nums[i + 1] {
			return nums[i]
		}
	}

	return 0
}
