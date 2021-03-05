int solve(vector<vector<int>>& matrix) {
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> sum_matrix(n, vector<int> (m));

    int max_n = 0;
    for (int i = 0; i < m; i++) {
        sum_matrix[0][i] = matrix[0][i];
        max_n = max(sum_matrix[0][i], max_n);
    }
    for (int i = 1; i < n; i++) {
        sum_matrix[i][0] = matrix[i][0];
        max_n = max(sum_matrix[i][0], max_n);
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (matrix[i][j]) {
                sum_matrix[i][j] = min(sum_matrix[i][j-1], min(sum_matrix[i-1][j], sum_matrix[i-1][j-1])) + 1;
                max_n = max(sum_matrix[i][j], max_n);
            }
        }
    }

    return max_n * max_n;
}