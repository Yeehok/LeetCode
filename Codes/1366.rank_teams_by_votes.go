func rankTeams(votes []string) (res string) {
	if len(votes) == 0 {
		return
	}

	voteNum := len(votes[0])

	ranking := make(map[byte]string)

	for i := range votes[0] {
		for j := 0; j < voteNum; j++ {
			ranking[votes[0][i]] += "0"
		}
	}

	for i := 0; i < voteNum; i++ {
		for _, v := range votes {
			t := []rune(ranking[v[i]])
			t[i] += 1
			ranking[v[i]] = string(t)
		}
	}

	//fmt.Println(ranking)

	for range votes[0] {
		var idx byte = 'Z'
		max := ""
		for i, v := range ranking {
			if v > max {
				max = v
				idx = i
			} else if v == max && i < idx {
				max = v
				idx = i
			}
		}
		res += string(idx)
		ranking[idx] = ""
	}

	return
}
