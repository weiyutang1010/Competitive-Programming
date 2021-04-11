/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
int solve(Tree* root, int t) {
    Tree* node = root;
    if (root) {
        int val = INT_MAX;
        // Find target node by binary search tree rule
        while (root->val != t) {
            // Keep track of value during the search as it could be the inorder sucessor
            if (root->val > t && root->val < val) {
                val = root->val;
            }

            if (t < root->val) {
                root = root->left;
            } else if (t > root->val) {
                root = root->right;
            }
        }

        // If node has at least 1 child, return node that is 1 right and all the way left
        if (root->right) {
            root = root->right;
            while (root->left != NULL) {
                root = root->left;
            }
            return root->val;
        }
        // If node has no child, the inorder sucessor is a node from root
        // to the t.
        return val;
    }
    return 0;
}