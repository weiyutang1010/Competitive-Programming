int dfs(vector<vector<int>>& graph, vector<int>& dp, int& ans, int curr) {
    if (dp[curr]) return dp[curr];

    for (auto& x: graph[curr]) {
        dp[curr] = max(dp[curr], dfs(graph, dp, ans, x) + 1);
    }
    return dp[curr];
}

int solve(vector<vector<int>>& graph) {
    int n = graph.size();
    int ans = 0;

    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        for (int& x: graph[i]) {
            v[x] = 1;
        }
    }

    // dfs every node and use dp to keep track of max value
    vector<int> dp(n);
    for (int i = 0; i < n; i++) {
        if (v[i] == 0) {
            dp[i] = max(dp[i], dfs(graph, dp, ans, i));
        }
    }

    return *max_element(dp.begin(), dp.end());
}