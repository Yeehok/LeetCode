func findSpecialInteger(arr []int) int {
	l := len(arr)

	q := l / 4 + 1
	sum := 0

	for i := 1; i < l; i++ {
		if arr[i] == arr[i-1] {
			sum++
		} else {
			sum = 0
		}
		if sum + 1 >= q {
			return arr[i]
		}
	}
	return arr[0]
}
