func arrayRankTransform(arr []int) (ans []int) {
	idx := make(map[int]int)

	cp := make([]int, len(arr))
	copy(cp, arr)

	sort.Ints(arr)

	i := 0
	last := -math.MaxInt32
	for _, v := range arr {
		if v != last {
			last = v
			i++
		}
		idx[v] = i
	}

	for _, v := range cp {
		ans = append(ans, idx[v])
	}
	return
}
