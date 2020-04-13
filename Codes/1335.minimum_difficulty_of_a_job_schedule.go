func minDifficulty(jobDifficulty []int, d int) int {
	l := len(jobDifficulty)
	if d > l {
		return -1
	}
	diffDuration := make([][]int, l)

	for i := 0; i < l; i++ {
		diffDuration[i] = make([]int, l)
	}

	for i := 0; i < l; i++ {
		for j := i; j < l; j++ {
			diffDuration[i][j] = 0
			for k := i; k <= j; k++ {
				if jobDifficulty[k] > diffDuration[i][j] {
					diffDuration[i][j] = jobDifficulty[k]
				}
			}
		}
	}

	dp := make([][]int, d)
	for i := 0; i < d; i++ {
		dp[i] = make([]int, l)
		for j := i; j < l; j++ {
			if i == 0 {
				dp[i][j] = diffDuration[i][j]
				continue
			}
			dp[i][j] = 10000
			for k := i - 1; k < j; k++ {
				if dp[i - 1][k] + diffDuration[k + 1][j] < dp[i][j] {
					dp[i][j] = dp[i - 1][k] + diffDuration[k + 1][j]
				}
			}
		}
	}

	return dp[d - 1][l - 1]
}
