func countLargestGroup(n int) (ans int) {
	cntSum := func(num int) (res int) {
		for num != 0 {
			res += num % 10
			num /= 10
		}
		return
	}

	group := make([]int, 37)

	max := 0
	for i := 1; i <= n; i++ {
		cur := cntSum(i)
		group[cur]++
		if group[cur] > max {
			max = group[cur]
			ans = 1
		} else if group[cur] == max {
			ans++
		}
	}

	return
}
