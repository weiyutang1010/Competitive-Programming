vector<vector<int>> solve(vector<vector<int>>& matrix) {
    const vector<pair<int, int>> dir {{0, 1}, {1, 0}, {-1, 0}, {0, -1}, {1, -1}, {-1, 1}, {1, 1}, {-1, -1}};
    int n = matrix.size(), m = matrix[0].size();
    vector<vector<int>> ans (n, vector<int> (m));

    // Check if the index is in bound
    auto valid = [&] (int i, int j) -> bool {
        return i >= 0 && i < n && j >= 0 && j < m;
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            // Find number of living neighbor
            int l_neigh = 0;
            for (auto& [x, y]: dir) {
                if (valid(i+x, j+y) && matrix[i+x][j+y] == 1) {
                    l_neigh++;
                }
            }

            // Check if current cell will be living based on number of living neighbor
            if (matrix[i][j] == 1 && (l_neigh >= 2 && l_neigh <= 3)) {
                ans[i][j] = 1;
            }
            if (matrix[i][j] == 0 && (l_neigh == 3)) {
                ans[i][j] = 1;
            }
        }
    }

    return ans;
}