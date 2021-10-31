/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */

bool post_order(Tree* root) {
    if (root->left && post_order(root->left)) {
        root->left = NULL;
    }

    if (root->right && post_order(root->right)) {
        root->right = NULL;
    }

    if (!root->left && !root->right) {
        return !(root->val & 1); // return true if node is a leaf and is even
    }
    return false;
}

Tree* solve(Tree* root) {
    if (root && post_order(root)){
        root = NULL;
    }
    return root;
}
