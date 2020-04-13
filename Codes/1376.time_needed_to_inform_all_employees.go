func numOfMinutes(n int, headID int, manager []int, informTime []int) int {
	costs := make([]int, len(manager))
	exist := make([]bool, len(manager))

	for _, v := range manager {
		if v == -1 {
			exist[headID] = true
		} else {
			exist[v] = true
		}
	}

	var calcCosts func(src int)
	calcCosts = func(src int) {
		if src == headID {
			return
		}
		if informTime[manager[src]] + costs[src] > costs[manager[src]] {
			costs[manager[src]] = informTime[manager[src]] + costs[src]
			calcCosts(manager[src])
		}
	}

	for i, v := range exist {
		if !v {
			calcCosts(i)
		}
	}

	return costs[headID]
}
