func diagonalSort(mat [][]int) [][]int {
	if len(mat) == 0 || len(mat[0]) == 0 {
		return mat
	}
	m := len(mat)
	n := len(mat[0])

	l := m
	if n < l {
		l = n
	}

	popSort := func(x, y int) {
		for i := 0; i < l - 1; i++ {
			for j := 0; j + x < m - 1 && j + y < n - 1; j++ {
				if mat[j + x][j + y] > mat[j + x + 1][j + y + 1] {
					mat[j + x][j + y], mat[j + x + 1][j + y + 1] = mat[j + x + 1][j + y + 1], mat[j + x][j + y]
				}
			}
		}
	}

	for i := 0; i < m; i++ {
		popSort(i, 0)
	}

	for i := 0; i < n; i++ {
		popSort(0, i)
	}

	return mat
}
