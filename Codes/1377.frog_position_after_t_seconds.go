func frogPosition(n int, edges [][]int, t int, target int) (result float64) {
	found := false
	var dfs func(curr int, prob int, depth int, nowProp float64, last int)
	dfs = func(curr int, prob int, depth int, nowProp float64, last int) {
		if found {
			return
		}

		if depth > t {
			return
		}

		nowProp /= float64(prob)

		if curr == target {
			result = nowProp
			if depth < t {
				for _, v := range edges {
					if v[0] == curr {
						if v[1] != last {
							result = 0
							break
						}
					} else if v[1] == curr {
						if v[0] != last {
							result = 0
							break
						}
					}
				}
			}
			found = true
			return
		}

		count := 0
		for _, v := range edges {
			if v[0] == last ||
				v[1] == last {
				continue
			}
			if v[0] == curr ||
				v[1] == curr {
				count++
			}
		}

		for _, v := range edges {
			if v[0] == last ||
				v[1] == last {
				continue
			}
			if v[0] == curr {
				dfs(v[1], count, depth + 1, nowProp, curr)
			} else if v[1] == curr {
				dfs(v[0], count, depth + 1, nowProp, curr)
			}
		}
	}
	dfs(1, 1, 0, 1, -1)

	return
}
