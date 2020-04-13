func numberOfSteps(num int) (ans int) {
	for num != 0 {
		if num % 2 == 0 {
			num /= 2
		} else {
			num--
		}
		ans++
	}
	return
}
