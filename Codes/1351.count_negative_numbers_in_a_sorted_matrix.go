func countNegatives(grid [][]int) (ans int) {
	for _, v := range grid {
		for i, iV := range v {
			if iV < 0 {
				ans += len(v) - i
				break
			}
		}
	}

	return
}
