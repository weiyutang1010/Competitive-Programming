vector<vector<int>> solve(vector<vector<int>>& matrix) {
    int n = matrix.size();
    vector<vector<int>> new_matrix(n, vector<int> (n));

    for (int i = 0; i < n; i++) {
        reverse(matrix[i].begin(), matrix[i].end());
        for (int j = 0; j < n; j++) {
            new_matrix[j][i] = matrix[i][j];
        }
    }

    return new_matrix;
}