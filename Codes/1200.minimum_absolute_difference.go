func minimumAbsDifference(arr []int) (res [][]int) {
	sort.Ints(arr)

	min := math.MaxInt32
	for i := 0; i < len(arr) - 1; i++ {
		if arr[i+1] - arr[i] < min {
			min = arr[i+1] - arr[i]
		}
	}

	for i := 0; i < len(arr) - 1; i++ {
		if arr[i+1] - arr[i] == min {
			res = append(res, []int{arr[i], arr[i + 1]})
		}
	}

	return
}
