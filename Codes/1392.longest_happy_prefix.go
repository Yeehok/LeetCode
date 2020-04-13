func longestPrefix(s string) string {
	l := len(s)

	for i := 1; i < l; i++ {
		if strings.HasSuffix(s, s[0: l - i]) {
			return s[0: l - i]
		}
	}

	return ""
}
