func canPartitionKSubsets(nums []int, k int) bool {
	total := 0
	for _, v := range nums {
		total += v
	}

	if total % k != 0 {
		return false
	}
	total /= k

	dump := make(map[int]bool)
	sort.Sort(sort.Reverse(sort.IntSlice(nums)))

	ans := false
	var dfs func(sum, cnt, used int)
	dfs = func(sum, cnt, used int) {
		if ans {
			return
		}
		if cnt == k {
			if used == len(nums) {
				ans = true
			}
		}
		for i, v := range nums {
			if dump[i] {
				continue
			}

			if sum + v > total {
				break
			}
			sum += v
			dump[i] = true
			if sum < total {
				dfs(sum, cnt, used + 1)
			} else if sum == total {
				dfs(0, cnt + 1, used + 1)
			}
			sum -= v
			dump[i] = false
		}
	}
	dfs(0, 0, 0)
	return ans
}