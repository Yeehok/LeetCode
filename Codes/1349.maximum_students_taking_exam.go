func maxStudents(seats [][]byte) (ans int) {
	if len(seats) == 0 || len(seats[0]) == 0 {
		return 0
	}
	m := len(seats)
	n := len(seats[0])

	dp := make([][]int, m)

	for i := range dp { // 状态需要2 ^ len的长度
		dp[i] = make([]int, int(math.Pow(2, float64(n))))
	}

	byteSeats := make([]int, m)

	for i := range byteSeats {
		for j := range seats[i] { // 按位压缩每一行的座椅位置
			byteSeats[i] <<= 1
			if seats[i][j] == '.' {
				byteSeats[i] += 1
			}
		}
	}

	max := func(a, b int) int {
		if a > b {
			return a
		}
		return b
	}

	cnt1 := func(v int) (ans int) { // 计算一个int里二进制表示有多少个1
		for ; v != 0; v >>= 1 {
			if v & 1 == 1 {
				ans++
			}
		}
		return
	}

	for i := 0; i < m; i++ {
		for j := 0; j < (1 << uint(n)); j++ {
			if j | byteSeats[i] != byteSeats[i] || // 不是需要的座位组合
				j & (j << 1) != 0 { // 邻座有人
				continue
			}

			for k := 0; k < (1 << uint(n)); k++ {
				if i == 0 {
					dp[i][j] = cnt1(j)
					break
				}
				if k | byteSeats[i - 1] != byteSeats[i - 1] ||
					k & (k << 1) != 0 ||
					((j << 1) & k) != 0 || // 两种情况分别是左前方右前方是否有人坐下
					((j >> 1) & k) != 0 {
					continue
				}
				dp[i][j] = max(dp[i][j], dp[i - 1][k] + cnt1(j))
			}
		}
	}

	for i := 0; i < (1 << uint(n)); i++ {
		if dp[m- 1][i] > ans {
			ans = dp[m- 1][i]
		}
	}

	return
}
