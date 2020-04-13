func findLucky(arr []int) int {
	sort.Ints(arr)

	cnt := 1
	for i := len(arr)-1; i >= 0; i-- {
		if i > 0 && arr[i] == arr[i-1] {
			cnt++
		} else {
			if cnt == arr[i] {
				return arr[i]
			}
			cnt = 1
		}
	}

	return -1
}
