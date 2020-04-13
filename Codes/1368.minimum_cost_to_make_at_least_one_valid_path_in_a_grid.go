func minCost(grid [][]int) int {
	lenX := len(grid)
	if lenX == 0 {
		return 0
	}
	lenY := len(grid[0])
	if lenY == 0 {
		return 0
	}
	cost := make([][]int, len(grid))
	for i := range cost {
		cost[i] = make([]int, len(grid[0]))
		for j := range cost[i] {
			cost[i][j] = -1
		}
	}

	cost[0][0] = 0

	type Coordinate struct {
		x, y int
	}

	queue := list.New()
	queue.PushBack(&Coordinate{0, 0})

	dir := [][]int{{0, 1}, {0, -1}, {1, 0}, {-1, 0}}
	for queue.Len() != 0 {
		curCoor := queue.Front().Value.(*Coordinate)

		for i, v := range dir {
			if curCoor.x + v[0] >= 0 &&
				curCoor.x + v[0] < lenX &&
				curCoor.y + v[1] >= 0 &&
				curCoor.y + v[1] < lenY {

				thisCost := 0
				if grid[curCoor.x][curCoor.y] != i + 1 {
					thisCost++
				}

				if cost[curCoor.x + v[0]][curCoor.y + v[1]] == -1 ||
					cost[curCoor.x + v[0]][curCoor.y + v[1]] > cost[curCoor.x][curCoor.y] + thisCost {

					cost[curCoor.x + v[0]][curCoor.y + v[1]] = cost[curCoor.x][curCoor.y] + thisCost

					queue.PushBack(&Coordinate{curCoor.x + v[0], curCoor.y + v[1]})
				}
			}
		}

		queue.Remove(queue.Front())
	}

	return cost[lenX - 1][lenY - 1]
}
