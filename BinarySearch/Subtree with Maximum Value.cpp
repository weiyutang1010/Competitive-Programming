/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
int ans;

// Return the sum of the subtree
int dfs(Tree* node) {
    if (!node) {
        // return 0 for null tree
        ans = max(ans, 0);
        return 0;
    }

    // sum = current value + sum of left subtree + sum of right subtree
    int val = node->val + dfs(node->left) + dfs(node->right);
    // keep track of max ans
    ans = max(ans, val);
    return val;
}

int solve(Tree* root) {
    ans = INT_MIN;
    ans = max(ans, dfs(root));
    return ans;
}