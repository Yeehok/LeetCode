func sumFourDivisors(nums []int) (ans int) {
	calcDivisors := func(num int) (ans int) {
		cnt := 0
		for i := 1; i <= int(math.Sqrt(float64(num))); i++ {
			if num % i == 0 {
				cnt ++
				ans += i
				if i != num / i {
					cnt++
					ans += num / i
				}
			}
			if cnt > 4 {
				break
			}
		}

		if cnt != 4 {
			return 0
		}
		return
	}

	for _, v := range nums {
		ans += calcDivisors(v)
	}
	return
}
