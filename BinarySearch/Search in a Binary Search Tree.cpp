/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
bool solve(Tree* root, int val) {
    if (!root) {
        return 0;
    }

    if (val == root->val) {
        return 1;
    } else if (val > root->val) {
        return solve(root->right, val);
    } else if (val < root->val) {
        return solve(root->left, val);
    }

    return 0;
}