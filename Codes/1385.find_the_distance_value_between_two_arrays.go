func findTheDistanceValue(arr1 []int, arr2 []int, d int) (ans int) {
	abs := func(a, b int) int {
		if a > b {
			return a - b
		}
		return b - a
	}

	for _, v1 := range arr1 {
		ans++
		for _, v2 := range arr2 {
			if abs(v1, v2) <= d {
				ans--
				break
			}
		}
	}
	return
}
