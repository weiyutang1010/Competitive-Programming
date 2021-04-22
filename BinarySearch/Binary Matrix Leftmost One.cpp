int solve(vector<vector<int>>& matrix) {
    int n = matrix.size();
    if (n <= 0) return -1;
    int m = matrix[0].size();

    int ans = INT_MAX;
    for (int i = 0; i < n; i++) {
        int l = 0, r = m - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (matrix[i][mid] == 1 && (mid == 0 || matrix[i][mid-1]==0)) {
                ans = min(ans, mid);
                break;
            } else if (matrix[i][mid] == 1) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
    }
    return ans == INT_MAX ? -1 : ans;
}