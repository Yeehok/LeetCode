func numTeams(rating []int) (ans int) {
	l := len(rating)

	for i := 0; i < l - 2; i++ {
		for j := l - 1; j > i + 1; j-- {
			if rating[i] == rating[j] {
				continue
			}

			for k := i + 1; k < j; k++ {
				if rating[i] < rating[k] && rating[k] < rating[j] {
					ans++
				} else if rating[i] > rating[k] && rating[k] > rating[j] {
					ans++
				}
			}
		}
	}

	return
}
