func angleClock(hour int, minutes int) float64 {
	hour %= 12
	minutes %= 60
	const degreePerCycle float64 = 360
	const degreePerHour = degreePerCycle / 12

	hourDegreeWithFix := (float64(hour) / 12 * degreePerCycle) + (float64(minutes) / 60 * degreePerHour)
	minutesDegree := float64(minutes) / 60 * degreePerCycle

	interval := math.Abs(hourDegreeWithFix - minutesDegree)

	if interval > degreePerCycle / 2 {
		return degreePerCycle - interval
	}
	return interval
}
