type firstSecond [][]int

func (ele firstSecond) Len() int {
	return len(ele)
}
func (ele firstSecond) Swap(i, j int) {
	ele[i], ele[j] = ele[j], ele[i]
}
func (ele firstSecond) Less(i, j int) bool {
	return ele[i][1] < ele[j][1]
}

func maxEvents(events [][]int) (ans int) {
	if len(events) == 0 {
		return
	}

	sort.Sort(firstSecond(events))

	dump := make(map[int]bool)

	for _, v := range events {
		for i := v[0]; i <= v[1]; i++ {
			if !dump[i] {
				dump[i] = true
				ans++
				break
			}
		}
	}

	return
}
