int solve(vector<vector<int>>& matrix) {
    int n = matrix.size(), m = matrix[0].size();
    set<int> rows, cols;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 1) {
                rows.insert(i);
                cols.insert(j);
            }
        }
    }

    return (n - rows.size()) * (m - cols.size());
}