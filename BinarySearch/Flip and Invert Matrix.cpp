vector<vector<int>> solve(vector<vector<int>>& matrix) {
    int n = matrix.size();
    if (n == 0) return matrix;
    int m = matrix[0].size();
    if (m == 0) return matrix;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m / 2; j++) {
            int temp = matrix[i][j];
            matrix[i][j] = 1 - matrix[i][m-j-1];
            matrix[i][m-j-1] = 1 - temp;
        }
        if (m & 1) {
            matrix[i][m/2] = 1 - matrix[i][m/2];
        }
    }

    return matrix;
}