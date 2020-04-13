func findNumbers(nums []int) (ans int) {
	digitEven := func(n int) bool {
		cnt := 0
		for n != 0 {
			cnt++
			n /= 10
		}
		return cnt%2 == 0
	}

	for _, v := range nums {
		if digitEven(v) {
			ans++
		}
	}

	return
}
