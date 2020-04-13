func sumZero(n int) (ans []int) {
	for i := 1; i <= n / 2; i++ {
		ans = append(ans, i)
		ans = append(ans, -i)
	}
	if n % 2 != 0 {
		ans = append(ans, 0)
	}

	return
}
