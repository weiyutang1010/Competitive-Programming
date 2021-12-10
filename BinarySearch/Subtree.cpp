/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */

// Check if the subtrees are identical
bool same_tree(Tree* node, Tree* target) {
    if (node && target) {
        if (node->val != target->val) {
            return false;
        }
        return same_tree(node->left, target->left) && same_tree(node->right, target->right);
    } else if (node || target) {
        return false;
    } else {
        return true;
    }
}

// Find node that matches target value
bool dfs(Tree* node, Tree* target) {
    if (!node) return false;

    if (node->val == target->val) {
        if (same_tree(node, target)) return true;
    }

    bool found = false;
    if (dfs(node->left, target)) found = true;
    if (dfs(node->right, target)) found = true;

    return found;
}

bool solve(Tree* root, Tree* target) {
    return dfs(root, target);
}
