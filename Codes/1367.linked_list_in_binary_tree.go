/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
func isSubPath(head *ListNode, root *TreeNode) (ans bool) {
	ans = false
	var search func(treeNode *TreeNode, listNode *ListNode)
	search = func(treeNode *TreeNode, listNode *ListNode) {
		if ans {
			return
		}

		if listNode == nil {
			ans = true
			return
		}

		if treeNode == nil {
			return
		}

		if treeNode.Val == listNode.Val {
			search(treeNode.Left, listNode.Next)
			search(treeNode.Right, listNode.Next)
		}
	}

	var dfs func(treeNode *TreeNode)
	dfs = func(treeNode *TreeNode) {
		if ans || treeNode == nil {
			return
		}

		search(treeNode, head)

		dfs(treeNode.Left)
		dfs(treeNode.Right)
	}

	dfs(root)
	return
}
