int solve(vector<vector<int>>& matrix) {
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> sum_matrix(n, vector<int> (m, 1));

    int max_n = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            int val = matrix[i][j];
            if (matrix[i-1][j] == val &&
                matrix[i][j-1] == val &&
                matrix[i-1][j-1] == val) {
                    sum_matrix[i][j] = min(sum_matrix[i-1][j-1], min(sum_matrix[i][j-1], sum_matrix[i-1][j])) + 1;
                    max_n = max(sum_matrix[i][j], max_n);
                }
        }
    }

    return max_n;
}