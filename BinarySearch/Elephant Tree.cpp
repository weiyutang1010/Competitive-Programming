/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
int recursion(Tree* root) {
    if (!root) return 0;
    if (!root->left && !root->right) return root->val;
    root->val += recursion(root->left) + recursion(root->right);
    return root->val;
}

Tree* solve(Tree* root) {
    if (root) {
        recursion(root);
    }
    return root;
}