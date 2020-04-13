func smallerNumbersThanCurrent(nums []int) (res []int) {
	for i, iv := range nums {
		res = append(res, 0)
		for j, jv := range nums {
			if i != j && jv < iv {
				res[i]++
			}
		}
	}

	return
}
