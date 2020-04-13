func numOfSubarrays(arr []int, k int, threshold int) (res int) {
	threshold *= k

	l := len(arr)
	cnt := 0
	for i := 0; i < k && i < l; i++ {
		cnt += arr[i]
	}
	for i := 0; i + k <= l; i++ {
		if i != 0 {
			cnt -= arr[i - 1]
			cnt += arr[i + k - 1]
		}
		if cnt >= threshold {
			res++
		}
	}
	return
}
