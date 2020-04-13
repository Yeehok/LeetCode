func kWeakestRows(mat [][]int, k int) (res []int) {
	for i := range mat {
		for _, v := range mat[i] {
			if v == 1 {
				mat[i][0] += 1
			}
		}
	}

	for i := 0; i < k; i++ {
		min := 100
		row := 0
		for i, v := range mat {
			if v[0] < min {
				min = v[0]
				row = i
			}
		}
		res = append(res, row)
		mat[row][0] = 100
	}
	return
}
