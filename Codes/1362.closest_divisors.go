func closestDivisors(num int) []int {
	ans := []int{0, math.MaxInt32}

	process := func(num int) {
		sqrt := int(math.Sqrt(float64(num))) + 1

		for i := sqrt; i >= 1; i-- {
			if num % i == 0 {
				if math.Abs(float64(ans[0] - ans[1])) > math.Abs(float64(num / i - i)) {
					ans[0] = i
					ans[1] = num / i
				}
				break
			}
		}
	}

	process(num + 1)
	process(num + 2)

	return ans
}
