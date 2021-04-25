int solve(vector<int>& weights, vector<int>& values, int capacity, int count) {
    int n = weights.size();
    // dp[i th object][capacity][count] = max value at ith object, capacity j, with atmost k items
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>> (capacity + 1, vector<int> (count + 1)));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= capacity; j++) {
            for (int k = 1; k <= count; k++) {
                if (i == 0 || j == 0 || k == 0) {
                    // When we are either considering 0 object, 0 capcity, or with at most 0 item
                    dp[i][j][k] = 0;
                } else {
                    if (weights[i - 1] <= j) {
                        // If current weight is smaller than capacity
                        // we can take last item + current item, or just last item
                        dp[i][j][k] = max(dp[i-1][j - weights[i-1]][k - 1] + values[i-1], dp[i-1][j][k]);
                    } else {
                        // weight > capacity and so we only consider what is already in the bag
                        dp[i][j][k] = dp[i - 1][j][k];
                    }
                }
            }
        }
    }

    return dp[n][capacity][count];
}