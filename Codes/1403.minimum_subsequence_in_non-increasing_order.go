type Int []int

func (arr Int) Len() int {
	return len(arr)
}

func (arr Int) Less(i, j int) bool {
	return arr[i] > arr[j]
}

func (arr Int) Swap(i, j int) {
	arr[i], arr[j] = arr[j], arr[i]
}

func minSubsequence(nums []int) (res []int) {
	sort.Sort(Int(nums))

	cnt := 0

	for _, v := range nums {
		cnt += v
	}

	subCnt := 0

	for _, v := range nums {
		subCnt += v
		res = append(res, v)
		if subCnt > cnt - subCnt {
			break
		}
	}
	return
}
