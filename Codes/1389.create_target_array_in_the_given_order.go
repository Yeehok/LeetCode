func createTargetArray(nums []int, index []int) (res []int) {
	if len(index) == 0 {
		return
	}
	lst := list.New()

	lst.PushBack(nums[index[0]])
	for i := 1; i < len(index); i++ {
		if index[i] == 0 {
			lst.PushFront(nums[i])
			continue
		}
		tar := lst.Front()
		for cnt := 1; cnt < index[i] && tar != nil; {
			cnt++
			tar = tar.Next()
		}
		lst.InsertAfter(nums[i], tar)
	}

	for p := lst.Front(); p != nil; p = p.Next() {
		res = append(res, p.Value.(int))
	}

	return
}
