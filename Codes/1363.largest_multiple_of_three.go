func largestMultipleOfThree(digits []int) (ans string) {
	sort.Ints(digits)

	exist := make(map[int]int)
	sum := 0

	for _, v := range digits {
		exist[v]++
		sum += v
	}

	if sum == 0 {
		ans = "0"
		return
	}

	remainder := sum % 3

	found := false
	dump := make(map[int]int)
	erase := make(map[int]int)
	var search func(left int, curSum int)
	search = func(left int, curSum int) {
		if found {
			return
		}
		if curSum % 3 == remainder {
			found = true
			for val, f := range dump {
				if f > 0 {
					erase[val] += f
				}
			}
			return
		}
		if left <= 0 {
			return
		}
		for _, v := range digits {
			if v == 0 || dump[v] >= exist[v] {
				continue
			}

			dump[v]++
			search(left - 1, curSum + v)
			dump[v]--
		}
	}

	if remainder != 0 {
		for i := 1; i <= len(digits); i++ {
			dump = make(map[int]int)
			search(i, 0)

			if found {
				erase[0] = 0
				break
			}
		}
	}

	for i := len(digits) - 1; i >= 0; i-- {
		if erase[digits[i]] > 0 {
			erase[digits[i]]--
			continue
		}
		ans += strconv.Itoa(digits[i])
	}

	return
}
