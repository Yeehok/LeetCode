func hasValidPath(grid [][]int) bool {
	m := len(grid)
	n := len(grid[0])

	dir := [][][]int{{{}},
		{{0, 1}, {0, -1}},
		{{1, 0}, {-1, 0}},
		{{0, -1}, {1, 0}},
		{{0, 1}, {1, 0}},
		{{0, -1}, {-1, 0}},
		{{-1, 0}, {0, 1}}}

	var dfs func(x, y int, lastX, lastY int) bool
	dfs = func(x, y int, lastX, lastY int) bool {
		if x < 0 || x >= m || y < 0 || y >= n {
			return false
		}
		if x == m - 1 && y == n - 1 {
			return (x + dir[grid[x][y]][0][0] == lastX &&
				y + dir[grid[x][y]][0][1] == lastY) ||
				(x + dir[grid[x][y]][1][0] == lastX &&
					y + dir[grid[x][y]][1][1] == lastY) ||
				(m == 1 && n ==1 )
		}

		if x != lastX || y != lastY {
			if x + dir[grid[x][y]][0][0] == lastX &&
				y + dir[grid[x][y]][0][1] == lastY {
				return dfs(x + dir[grid[x][y]][1][0], y + dir[grid[x][y]][1][1], x, y)
			} else if x + dir[grid[x][y]][1][0] == lastX &&
				y + dir[grid[x][y]][1][1] == lastY {
				return dfs(x + dir[grid[x][y]][0][0], y + dir[grid[x][y]][0][1], x, y)
			} else {
				return false
			}
		}

		return dfs(x + dir[grid[x][y]][1][0], y + dir[grid[x][y]][1][1], x, y) ||
			dfs(x + dir[grid[x][y]][0][0], y + dir[grid[x][y]][0][1], x, y)
	}

	return dfs(0, 0, 0, 0)
}
