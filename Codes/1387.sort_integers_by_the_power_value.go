type firstSecond [][]int

func (ele firstSecond) Len() int {
	return len(ele)
}
func (ele firstSecond) Swap(i, j int) {
	ele[i], ele[j] = ele[j], ele[i]
}
func (ele firstSecond) Less(i, j int) bool {
	if ele[i][0] == ele[j][0] {
		return ele[i][1] < ele[j][1]
	}
	return ele[i][0] < ele[j][0]
}

func getKth(lo int, hi int, k int) int {
	rec := make(map[int]int)
	getPow := func(src int) (ans int) {
		if v, f := rec[src]; f {
			return v
		}
		for src != 1 {
			if src % 2 == 0 {
				src /= 2
			} else {
				src *= 3
				src++
			}
			ans++
		}
		rec[src] = ans
		return
	}

	arr := make([][]int, hi - lo + 1)
	for j := lo; j <= hi; j++ {
		arr[j - lo] = []int{getPow(j), j}
	}

	sort.Sort(firstSecond(arr))

	fmt.Println(arr)

	return arr[k - 1][1]
}
