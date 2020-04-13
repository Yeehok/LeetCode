func breakPalindrome(palindrome string) string {
	l := len(palindrome)
	if l == 1 {
		return ""
	}

	bytes := []byte(palindrome)

find:
	for t := 0; t < 26; t++ {
		for i := 0; i < l; i++ {
			if l % 2 == 1 && i == l / 2 {
				continue
			}
			if bytes[i] != byte(t) + 'a' && (bytes[i] > byte(t) + 'a' || i == l - 1) {
				bytes[i] = byte(t) + 'a'
				break find
			}
		}
	}

	return string(bytes)
}
