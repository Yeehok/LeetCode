/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int m_target;
    bool DFS(TreeNode *node) {
        if (node == nullptr) return false;
        if (DFS(node->left)) {
            node->left = nullptr;
        }
        if (DFS(node->right)) {
            node->right = nullptr;
        }
        return (node->val == m_target
               && node->left == nullptr
               && node->right == nullptr);
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        m_target = target;
        if (DFS(root)) return nullptr;
        return root;
    }
};
