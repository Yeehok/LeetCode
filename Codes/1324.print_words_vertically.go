func printVertically(s string) []string {
	var res []string
	split := strings.Split(s, " ")
	max := 0
	for i := range split {
		if len(split[i]) > max {
			max = len(split[i])
		}
	}
	for i := 0; i < max; i++ {
		res = append(res, "")
		for j := range split {
			if len(split[j]) > i {
				res[i] += string(split[j][i])
			} else {
				res[i] += " "
			}
		}
	}
	for i := range res {
		res[i] = strings.TrimRight(res[i], " ")
	}
	return res
}
