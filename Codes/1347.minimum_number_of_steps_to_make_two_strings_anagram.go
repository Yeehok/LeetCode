func minSteps(s string, t string) (ans int) {
	cnt := make([]int, 26)

	for _, v := range s {
		cnt[v - 'a']++
	}

	for _, v := range t {
		if cnt[v - 'a'] > 0 {
			cnt[v - 'a']--
		} else {
			ans++
		}
	}

	return
}
