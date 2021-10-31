/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
unordered_map<int, int> mp;

int dfs(Tree* node) {
    if (!node) {
        return 0;
    }

    int subtree = node->val + dfs(node->left) + dfs(node->right);
    mp[subtree]++;
    return subtree;
}

int solve(Tree* root) {
    mp.clear();
    dfs(root);

    int ans = 0, curr = 0;
    for (auto& [x, y]: mp) {
        if (y > curr) {
            curr = y;
            ans = x;
        }
    }
    return ans;
}
