type sortBytes []int

func (ele sortBytes) Len() int {
	return len(ele)
}

func (ele sortBytes) Swap(i, j int) {
	ele[i], ele[j] = ele[j], ele[i]
}

func (ele sortBytes) Less(i, j int) bool {
	cntI := 0
	cntJ := 0

	vi := ele[i]
	vj := ele[j]
	for vi != 0 {
		if vi % 2 == 1 {
			cntI++
		}
		vi /= 2
	}

	for vj != 0 {
		if vj % 2 == 1 {
			cntJ++
		}
		vj /= 2
	}

	if cntI == cntJ {
		return ele[i] < ele[j]
	}

	return cntI < cntJ
}

func sortByBits(arr []int) []int {
	sort.Sort(sortBytes(arr))

	return arr
}
