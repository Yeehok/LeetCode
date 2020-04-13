func filterRestaurants(restaurants [][]int, veganFriendly int, maxPrice int, maxDistance int) (res []int) {
	for {
		found := false
		maxRate := 0
		idx := 0
		num := 0
		for i, v := range restaurants {
			if (veganFriendly == 0 || v[2] == 1) &&
				v[3] <= maxPrice &&
				v[4] <= maxDistance {
				if v[1] > maxRate || (v[1] == maxRate && v[0] > num) {
					maxRate = v[1]
					found = true
					idx = i
					num = v[0]
				}
			}
		}

		if !found {
			break
		}
		res = append(res, num)
		restaurants[idx][1] = -1
	}
	return
}
