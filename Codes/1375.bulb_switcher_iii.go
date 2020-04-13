func numTimesAllBlue(light []int) (ans int) {
	top := -1
	for i, v := range light {
		if v > top {
			top = v
		}
		if top <= i + 1 {
			ans++
		}
	}
	return
}
