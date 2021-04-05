/**
 * class Tree {
 *     public:
 *         int val;
 *         Tree *left;
 *         Tree *right;
 * };
 */

void dfs(Tree* root, int height, int idx, int& lmost, int& rmost, vector<vector<pair<int, int>>>& v) {
    if (!root) return;
    lmost = min(idx, lmost);
    rmost = max(idx, rmost);

    if (height >= v.size()) v.push_back(vector<pair<int, int>> ());
    v[height].push_back(make_pair(root->val, idx));

    if (root->left) {
        dfs(root->left, height + 1,idx-1, lmost, rmost, v);
    }

    if (root->right) {
        dfs(root->right, height + 1,idx+1, lmost, rmost, v);
    }

    return;
}

vector<int> solve(Tree* root) {
    vector<vector<pair<int, int>>> v;
    int lmost = 0, rmost = 0;
    dfs(root, 0, 0, lmost, rmost, v);

    vector<int> ans(rmost - lmost + 1, -1);
    for (int i = 0; i < v.size(); i++) {
        for (int j = 0; j < v[i].size(); j++) {
            if (ans[v[i][j].second - lmost] == -1) {
                ans[v[i][j].second - lmost] = v[i][j].first;
            }
        }
    }
    
    return ans;
}