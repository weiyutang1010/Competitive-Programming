vector<vector<int>> solve(vector<vector<int>>& matrix) {
    int n = matrix.size();
    if (!n) return matrix;
    int m = matrix[0].size();
    if (!m) return matrix;
    vector<vector<int>> v(max(n, m), vector<int> (2));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            v[i][0] = max(v[i][0], matrix[i][j]);
            v[j][1] = max(v[j][1], matrix[i][j]);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            matrix[i][j] = min(v[i][0], v[j][1]);
        }
    }

    return matrix;
}
