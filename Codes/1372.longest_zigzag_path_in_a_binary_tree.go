/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func longestZigZag(root *TreeNode) (res int) {
	dump := make(map[*TreeNode]int8)

	cur := 0

	var dfs func(dir bool, node *TreeNode)
	dfs = func(dir bool, node *TreeNode) {
		if node == nil {
			return
		}

        if (dump[node] & 3) == 3 {
			return
		}

		if cur > res {
			res = cur
		}

		if dir && (dump[node] & 1) == 0 {
			cur++
			dump[node] |= 1
			dfs(!dir, node.Left)
			cur--
		} else if !dir && (dump[node] & 2) == 0 {
			cur++
			dump[node] |= 2
			dfs(!dir, node.Right)
			cur--
		}
	}

	var op func(node *TreeNode)
	op = func(node *TreeNode) {
		if node == nil {
			return
		}

		dfs(true, node)
		dfs(false, node)

		op(node.Left)
		op(node.Right)
	}

	op(root)

	return
}
