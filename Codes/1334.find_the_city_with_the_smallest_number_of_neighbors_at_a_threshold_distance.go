func findTheCity(n int, edges [][]int, distanceThreshold int) (res int) {
	var cities = make([][]int, n)
	for i := range cities {
		cities[i] = make([]int, n)
	}

	for _, v := range edges {
		cities[v[0]][v[1]] = v[2]
		cities[v[1]][v[0]] = v[2]
	}

	for k := 0; k < n; k++ {
		for i := 0; i < n; i++ {
			for j := 0; j < n; j++ {
				if i == j ||
					cities[i][k] == 0 ||
					cities[k][j] == 0 {
					continue
				}
				if cities[i][j] == 0 || cities[i][j] > cities[i][k] + cities[k][j] {
					cities[i][j] = cities[i][k] + cities[k][j]
				}
			}
		}
	}

	var minCnt = 101
	for i := 0; i < n; i++ {
		var curCnt = 0
		for j := 0; j < n; j++ {
			if i != j && cities[i][j] != 0 && cities[i][j] <= distanceThreshold {
				curCnt++
			}
		}
		if curCnt <= minCnt {
			res = i
			minCnt = curCnt
		}
	}

	return
}
