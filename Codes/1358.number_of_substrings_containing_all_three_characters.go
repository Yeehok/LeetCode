func numberOfSubstrings(s string) (res int) {
	l := len(s)

	searchSubstring := func(idx int) int {
        exist := make([]int, 3)
		st := idx
		i := idx
        found := false
        check := func() bool {
            if exist[0] > 0 && exist[1] > 0 && exist[2] > 0 {
                return true
            }
            return false
        }
		for ; i < l; i++ {
			exist[s[i] - 'a']++
            for check() {
                found = true
                exist[s[idx] - 'a']--
                idx++
            }
			if found {
				idx--
				exist[s[idx] - 'a']++
                break
			}
		}
		if found {
			res += (idx - st + 1) * (l - i)
		}
		return idx + 1
	}

	for i := 0; i < l; i = searchSubstring(i) {

	}

	return
}
