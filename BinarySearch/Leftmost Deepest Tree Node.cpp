/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
void dfs(Tree* node, array<int, 3>& ans, int depth, int left) {
    // Always go left first if possible
    if (node->left) {
        dfs(node->left, ans, depth + 1, left + 1);
    }

    if (node->right) {
        dfs(node->right, ans, depth + 1, left - 1);
    }

    if (depth > ans[1]) {
        ans = {node->val, depth, left};
    }
    
    return;
}

int solve(Tree* root) {
    array<int, 3> ans; // {value, depth, how far left it is from root}
    if (root) {
        ans = {root->val, 0, 0};
        dfs(root, ans, 0, 0);
    }
    return ans[0];
}