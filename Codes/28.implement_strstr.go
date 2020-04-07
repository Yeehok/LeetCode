func strStr(haystack string, needle string) int {
	if len(needle) <= 0 {
		return 0
	}
    l := len(haystack)
	out:
	for i := range haystack {
		if haystack[i] == needle[0] {
			idx := i
			for j := range needle {
				if idx >= l || haystack[idx] != needle[j] {
					continue out
				}
				idx++
			}
			return i
		}
	}

	return -1
}
