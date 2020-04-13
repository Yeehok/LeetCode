/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func maxSumBST(root *TreeNode) (ans int) {
	dump := make(map[*TreeNode]bool)
	summary := make(map[*TreeNode]int)

	var dfsBST func(node *TreeNode, left bool, dad *TreeNode) bool
	dfsBST = func(node *TreeNode, left bool, dad *TreeNode) bool {
		if node == nil {
			return true
		}

		v, f := dump[node]
		if f {
			return v
		}

		if dfsBST(node.Left, true, node) && dfsBST(node.Right, false, node) {
			if dad != nil {
				if left && node.Val >= dad.Val {
					return false
				} else if !left && node.Val <= dad.Val {
					return false
				}
			}
			dump[node] = true
			return true
		}

		dump[node] = false
		return false
	}

	var sum func(node *TreeNode) int
	sum = func(node *TreeNode) int {
		if node == nil {
			return 0
		}

		summary[node] = sum(node.Left) + sum(node.Right) + node.Val

		return summary[node]
	}

	var search func(node *TreeNode)
	search = func(node *TreeNode) {
		if node == nil {
			return
		}

		_, f := dump[node]
		if !f {
			dump[node] = dfsBST(node, true, nil)
		}
		
		search(node.Left)
		search(node.Right)
	}
	search(root)
	sum(root)

	for n, f := range dump {
		if f {
			if summary[n] > ans {
				ans = summary[n]
			}
		}
	}

	return
}
