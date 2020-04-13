func luckyNumbers(matrix [][]int) (ans []int) {
	for _, row := range matrix {
		min := math.MaxInt32
		idx := -1
		for i, v := range row {
			if v < min {
				min = v
				idx = i
			}
		}
		for i := 0; i < len(matrix); i++ {
			if matrix[i][idx] > min {
				idx = -1
				break
			}
		}
		if idx != -1 {
			ans = append(ans, min)
		}
	}

	return
}
