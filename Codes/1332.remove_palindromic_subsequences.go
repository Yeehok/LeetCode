func removePalindromeSub(s string) int {
	l := len(s)
	for i := range s {
		if i >= l - i {
			break
		}
		if s[i] != s[l - i - 1] {
			return 2
		}
	}
	if l != 0 {
		return 1
	} else {
		return 0
	}
}
