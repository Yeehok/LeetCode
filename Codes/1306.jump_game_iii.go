func canReach(arr []int, start int) bool {
	l := len(arr)

	dump := make([]bool, l)

	var dfs func(curr int) bool
	dfs = func(curr int) bool {
		if arr[curr] == 0 {
			return true
		}

		ret := false
		if curr - arr[curr] >= 0 && !dump[curr - arr[curr]] {
			dump[curr - arr[curr]] = true
			ret = ret || dfs(curr - arr[curr])
		}
		if curr + arr[curr] < l && !dump[curr + arr[curr]] {
			dump[curr + arr[curr]] = true
			ret = ret || dfs(curr + arr[curr])
		}
		return ret
	}

	return dfs(start)
}
