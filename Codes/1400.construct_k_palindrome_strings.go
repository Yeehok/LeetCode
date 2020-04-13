func canConstruct(s string, k int) bool {
	if len(s) < k {
		return false
	}
	str := make([]int, 26)

	for _, v := range s {
		str[v - 'a']++
	}

	odd := 0
	for i := 0; i < 26; i++ {
		if str[i]%2 == 1 {
			odd++
		}
	}

	return odd <= k
}
