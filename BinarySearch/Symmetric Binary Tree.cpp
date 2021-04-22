/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */

bool dfs(Tree* node1, Tree* node2) {
    if (node1 && node2) {
        if (node1->val != node2->val) {
            return false;
        }
        return dfs(node1->right, node2->left) && dfs(node1->left, node2->right);
    } else if (!node1 && !node2) {
        return true;
    }
    return false;
}

bool solve(Tree* root) {
    if (root) {
        return dfs(root->left, root->right);
    }
    return true;
}