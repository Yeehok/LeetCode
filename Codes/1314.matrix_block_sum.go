func matrixBlockSum(mat [][]int, K int) (res [][]int) {
	var n int
	var m = 0
	m = len(mat)
	if m > 0 {
		n = len(mat[0])
	}

	for i := 0; i < m; i++ {
		var temp []int
		for j := 0; j < n; j++ {
			var sum = 0
			for k := i - K; k <= i + K; k++ {
				if k < 0 || k >= m {
					continue
				}
				for l := j - K; l <= j + K; l++ {
					if  l < 0 || l >= n {
						continue
					}
					sum = sum + mat[k][l]
				}
			}

			temp = append(temp, sum)
		}
		res = append(res, temp)
	}

	return res
}
