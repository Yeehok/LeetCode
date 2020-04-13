type Ele struct {
	val int
	sum int
}

func satisfied(arr []Ele, tar int, l int) bool {
	reduce := 0
	for _, v := range arr {
		if tar > 0 {
			tar--
			reduce += v.sum
		}
	}

	return l / 2 <= reduce
}

//noinspection ALL
func minSetSize(arr []int) (res int) {
	var arrNew []Ele
	sort.Ints(arr)
	last := -1
	for _, v := range arr {
		if v != last {
			arrNew = append(arrNew, Ele{v, 1})
			last = v
		} else {
			l := len(arrNew)
			arrNew[l - 1].sum++
		}
	}
	sort.Slice(arrNew, func(i, j int) bool {
		return arrNew[i].sum > arrNew[j].sum
	})
	l := 0
	r := len(arr)
	mid := 0
	length := r
	for l <= r {
		mid = (l + r) / 2
		if satisfied(arrNew, mid, length) {
			res = mid
			r = mid - 1
		} else {
			l = mid + 1
		}
	}
	return
}
