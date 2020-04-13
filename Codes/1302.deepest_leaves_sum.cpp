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
    int sum;

    struct Node {
        TreeNode *node;
        int dep;
        Node(TreeNode *n = NULL, int d = 0)
        : node(n)
        , dep(d) {

        }
    };

    int deepestLeavesSum(TreeNode* root) {
        queue<Node> q;
        q.push(Node(root, 1));
        int max = 0;
        vector<Node> ans;

        Node f;
        while (!q.empty()) {
            f = q.front();
            q.pop();
            ans.emplace_back(f);

            if (f.node->left != NULL) {
                q.push(Node(f.node->left, f.dep + 1));
            }
            if (f.node->right != NULL) {
                q.push(Node(f.node->right, f.dep + 1));
            }
        }

        for (auto i : ans) {
            if (i.dep > max) max = i.dep;
        }

        int res = 0;
        for (auto i : ans) {
            if (i.dep == max) res += i.node->val;
        }

        return res;
    }
};
