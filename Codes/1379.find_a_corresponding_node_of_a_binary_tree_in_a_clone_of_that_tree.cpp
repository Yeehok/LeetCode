class Solution {
public:
    TreeNode* DFS(TreeNode* o, TreeNode* c, TreeNode* target) {
        if (o == nullptr) return nullptr;

        if (c == nullptr) return nullptr;

        if (o == target) {
            return c;
        }

        TreeNode* res = nullptr;
        if (o->left) res = DFS(o->left, c->left, target);
        if (res == nullptr && o->right) res = DFS(o->right, c->right, target);
        return res;
    }

    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        return DFS(original, cloned, target);
    }
};
