func countOrders(n int) int {
	var secondary func(n int) int
	secondary = func(n int) (res int) {
		res = 1
		if n > 1 {
			res += 5
		}
		if n > 2 {
			res += 9 * (n - 2)
		}
		if n > 3 {
			res += 4 * (((n - 3) * (n - 3) + n - 3) / 2)
		}
		return
	}

	var cnt func(n int) int
	cnt = func(n int) (res int) {
		if n == 1 {
			return 1
		}
		res = cnt(n - 1) % 1000000007
		sec := secondary(n) % 1000000007
		return (res * sec) % 1000000007
	}

	return cnt(n)
}
