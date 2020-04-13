func isPossible(target []int) (found bool) {
	max := 0
	idx := 0
	sum := 0
	for i, v := range target {
		sum += v
		if v > max {
			max = v
			idx = i
		}
	}

	if max == 1 {
		return true
	}

	left := sum - max

	if left == 0 {
		return false
	}
	target[idx] %= left
	if target[idx] == 0 {
		target[idx] = left
	}
	if target[idx] == max {
		return false
	}

	return isPossible(target)
}
