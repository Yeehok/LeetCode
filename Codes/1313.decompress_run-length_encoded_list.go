func decompressRLElist(nums []int) []int {
	var res []int

	for i, v := range nums {
		if i % 2 == 0 {
			for j := 0; j < v; j++ {
				res = append(res, nums[i + 1])
			}
		}
	}

	return res
}
