func maxJumps(arr []int, d int) int {
	l := len(arr)
	prefer := make([]int, l)
	for i := range prefer {
		prefer[i] = 1
	}

	dump := make([]bool, l)
	for i := 0; i < l; i++ {
		min := math.MaxInt32
		idx := 0
		for j, v := range arr {
			if v < min && !dump[j] {
				min = v
				idx = j
			}
		}
		dump[idx] = true

		src := prefer[idx]
		for j := idx + 1; j <= idx + d && j < l; j++ {
			if arr[idx] <= arr[j] {
				break
			}
			if src + prefer[j] > prefer[idx] {
				prefer[idx] = src + prefer[j]
			}
		}
		for j := idx - 1; j >= idx - d && j >= 0; j-- {
			if arr[idx] <= arr[j] {
				break
			}
			if src + prefer[j] > prefer[idx] {
				prefer[idx] = src + prefer[j]
			}
		}
	}

	max := 0
	for i := 0; i < l; i++ {
		if prefer[i] > max {
			max = prefer[i]
		}
	}
	return max
}
