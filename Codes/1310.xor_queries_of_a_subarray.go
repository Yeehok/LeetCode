func xorQueries(arr []int, queries [][]int) (res []int) {
	size := len(arr)
	table := make([]int, size)
	if size <= 0 {
		return
	}
	table[0] = arr[0]
	for i := 1; i < size; i++ {
		table[i] = table[i - 1] ^ arr[i]
	}

	for _, v := range queries {
		var tmp int
		if v[0] - 1 >= 0 {
			tmp = table[v[0] - 1]
			tmp ^= table[v[1]]
		} else {
			tmp = table[v[1]]
		}
		res = append(res, tmp)
	}

	return
}
