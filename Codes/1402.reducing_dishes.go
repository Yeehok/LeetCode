func maxSatisfaction(satisfaction []int) (max int) {
	sort.Ints(satisfaction)

	l := len(satisfaction)

	for i := l; i >= 0; i-- {
		cur := 0
		idx := l - 1
		for j := i; j >= 1; j-- {
			cur += satisfaction[idx] * j
			idx--
		}

		if cur > max {
			max = cur
		}
	}
	return max
}
