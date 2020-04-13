func findPoisonedDuration(timeSeries []int, duration int) (res int) {
	last := -1
	if len(timeSeries) > 0 {
		last = timeSeries[0]
		res = duration
	}
	for _, v := range timeSeries {
		if v - last >= duration {
			res += duration
		} else {
			res += v - last
		}
		last = v
	}

	return
}
