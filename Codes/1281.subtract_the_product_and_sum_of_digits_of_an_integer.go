func subtractProductAndSum(n int) int {
	pro := 1
	sum := 0
	for n != 0 {
		pro *= n%10
		sum += n%10
		n /= 10
	}
	return pro - sum
}
