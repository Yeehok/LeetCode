/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
var ans int
var ansLeft int
var ansRight int

func sumNodes(node *TreeNode) int {
	if node == nil {
		return 0
	}
	if node.Left != nil && node.Right != nil {
		node.Val += sumNodes(node.Left) + sumNodes(node.Right)
	} else if node.Left != nil {
		node.Val += sumNodes(node.Left)
	} else if node.Right != nil {
		node.Val += sumNodes(node.Right)
	}

	return node.Val
}

func traversal(root *TreeNode, rootVal int) {
	if root == nil {
		return
	}

	if root.Left != nil {
		val := root.Left.Val - rootVal + root.Left.Val
		if val > 0 {
			if val < ans {
				ans = val
				ansLeft = root.Left.Val
				ansRight = rootVal - root.Left.Val
			}
			traversal(root.Left, rootVal)
		} else {
			if -val < ans {
				ans = -val
				ansLeft = root.Left.Val
				ansRight = rootVal - root.Left.Val
			}
		}
	}
	if root.Right != nil {
		val := root.Right.Val - rootVal + root.Right.Val
		if val > 0 {
			if val < ans {
				ans = val
				ansLeft = root.Right.Val
				ansRight = rootVal - root.Right.Val
			}
			traversal(root.Right, rootVal)
		} else {
			if -val < ans {
				ans = -val
				ansLeft = root.Right.Val
				ansRight = rootVal - root.Right.Val
			}
		}
	}
}

func maxProduct(root *TreeNode) int {
	sumNodes(root)
	ans = math.MaxInt32

	traversal(root, root.Val)

	return ((ansLeft % 1000000007) * (ansRight % 1000000007)) % 1000000007
}
