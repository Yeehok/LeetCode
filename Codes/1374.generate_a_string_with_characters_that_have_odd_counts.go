func generateTheString(n int) (ans string) {
	for i := 0; i < n - 1; i++ {
		ans += "a"
	}
	if n % 2 == 0 {
		ans += "b"
	} else {
		ans += "a"
	}
	return
}
