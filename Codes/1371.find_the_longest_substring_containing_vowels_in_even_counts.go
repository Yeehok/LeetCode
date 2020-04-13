func findTheLongestSubstring(s string) (res int) {
	dic := make(map[int]int)
	dic[0] = -1
	state := make([]int, 26)

	hash := func() (hashRes int) {
		for _, v := range state {
			hashRes |= v
			hashRes <<= 1
		}
		return
	}

	for i := 0; i < len(s); i++ {
		if s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' {
			state[s[i] - 'a']++
			state[s[i] - 'a'] %= 2
		}

		hashRes := hash()

		v, f := dic[hashRes]
		if f {
			if i - v > res {
				res = i - v
			}
		} else {
			dic[hashRes] = i
		}
	}
	return
}
