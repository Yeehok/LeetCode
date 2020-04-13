/**
 * Definition for a binary tree node.
 * type TreeNode struct {
 *     Val int
 *     Left *TreeNode
 *     Right *TreeNode
 * }
 */
class Solution {
public:
    int summary;
    void SummaryForGrandson(TreeNode *node, int &sum) {
        if (node->left != nullptr) {
            if (node->left->left != nullptr) sum += node->left->left->val;
            if (node->left->right != nullptr) sum += node->left->right->val;
        }
        if (node->right != nullptr) {
            if (node->right->left != nullptr) sum += node->right->left->val;
            if (node->right->right != nullptr) sum += node->right->right->val;
        }
    }
    void Traversal(TreeNode *node) {
        if (node == nullptr) return;

        if (node->val % 2 == 0) {
            SummaryForGrandson(node, summary);
        }

        Traversal(node->left);
        Traversal(node->right);
    }
    int sumEvenGrandparent(TreeNode* root) {
        summary = 0;

        Traversal(root);

        return summary;
    }
};
