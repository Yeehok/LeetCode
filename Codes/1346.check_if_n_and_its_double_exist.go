func checkIfExist(arr []int) bool {
	chk := make(map[int]bool)

    zero := 0
	for _, v := range arr {
		chk[v] = true
        if v == 0 {
            zero++
        }
	}

	for _, v := range arr {
		if chk[v * 2] {
            if v != 0 || zero > 1 {
                return true
            }
		}
	}
	return false
}
