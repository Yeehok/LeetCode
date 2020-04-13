func freqAlphabets(s string) string {
	var res bytes.Buffer
	var tmp byte
	size := len(s)
	for i := 0; i < size; i++ {
		if i + 2 < size && s[i + 2] == '#' {
			tmp = s[i + 1] - '0'
			tmp += (s[i] - '0') * 10
			i += 2
		} else {
			tmp = s[i] - '0'
		}
		res.WriteString(string(tmp + 'a' - 1))
	}
	return res.String()
}
