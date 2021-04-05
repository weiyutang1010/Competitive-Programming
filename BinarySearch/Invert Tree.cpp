/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
Tree* dfs(Tree* root) {
    if (!root) return root;

    if (root->left || root->right) {
        Tree* temp = root->left;
        root->left = root->right;
        root->right = temp;
    }

    if (root->left) {
        dfs(root->left);
    }

    if (root->right) {
        dfs(root->right);
    }    
    return root;
}

Tree* solve(Tree* root) {
    if (root) {
        dfs(root);
    }
    return root;
}