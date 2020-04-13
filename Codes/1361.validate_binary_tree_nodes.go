func validateBinaryTreeNodes(n int, leftChild []int, rightChild []int) (ans bool) {
	dump := make(map[int]bool)

	res := false
	var dfs func(curr int)
	dfs = func(curr int) {
		if curr == -1 || res {
			return
		}

		if dump[curr] {
			res = true
			ans = false
			return
		}

		dump[curr] = true

		dfs(leftChild[curr])
		dfs(rightChild[curr])
	}

	for i := 0; i < n; i++ {
		dump = make(map[int]bool)
		dfs(i)

		if !res && len(dump) == n {
			res = true
			ans = true
			break
		}
	}

	return
}
