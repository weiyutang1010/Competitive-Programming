/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
Tree* solve(Tree* root) {
    vector<int> v;
    queue<Tree*> Q;
    Q.push(root);

    while (!Q.empty()) {
        Tree* node = Q.front();
        Q.pop();

        v.push_back(node->val);
        if (node->left) Q.push(node->left);
        if (node->right) Q.push(node->right);
    }

    int n = v.size();
    sort(v.begin(), v.end());

    vector<int> sum(n);
    sum[n-1] = v[n-1];
    for (int i = n-2; i >= 0; i--) {
        sum[i] = sum[i+1] + v[i];
    }

    Q.push(root);
    while (!Q.empty()) {
        Tree* node = Q.front();
        Q.pop();

        int up = upper_bound(v.begin(), v.end(), node->val) - v.begin();
        if (up < sum.size()) node->val += sum[up];

        if (node->left) Q.push(node->left);
        if (node->right) Q.push(node->right);
    }

    return root;
}

// Solution 2: Cleaner solution with reverse in_order traversal
/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */
void dfs(Tree* node, int& acc) {
    if (!node) return;

    if (node->right) dfs(node->right, acc);

    node->val += acc;
    acc += node->val - acc;

    if (node->left) dfs(node->left, acc);
}

Tree* solve(Tree* root) {
    int acc = 0;
    if (root) dfs(root, acc);
    return root;
}
