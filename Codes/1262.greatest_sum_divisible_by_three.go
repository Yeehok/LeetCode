func maxSumDivThree(nums []int) (ans int) {
	sort.Ints(nums)

	exist := make(map[int]int)
	sum := 0

	for _, v := range nums {
		exist[v]++
		sum += v
	}

	remainder := sum % 3

	found := false
	dump := make(map[int]int)
	var search func(left int, curSum int)
	search = func(left int, curSum int) {
		if curSum % 3 == remainder {
			found = true
			if sum - curSum > ans {
				ans = sum - curSum
			}
			return
		}
		if found || curSum > sum - ans || left <= 0 {
			return
		}
		for _, v := range nums {
			if v % 3 == 0 {
				continue
			}
			if found {
				return
			}
			if dump[v] >= exist[v] {
				continue
			}

			dump[v]++
			search(left - 1, curSum + v)
			dump[v]--
		}
	}

	if remainder != 0 {
		for i := 1; i <= len(nums); i++ {
			dump = make(map[int]int)
			found = false
			search(i, 0)
		}
	} else {
		ans = sum
	}

	return
}
