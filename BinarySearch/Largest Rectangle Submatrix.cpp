int solve(vector<vector<int>>& matrix) {
    // If any row/col length is 0, return 0
    int n = matrix.size();
    if (n == 0) return 0;
    int m = matrix[0].size();
    if (m == 0) return 0;

    // Precompute left array to obtain width
    // left[i][j] = index of first element to the left of i, j that is equal to 0
    // left[i][j] = INT_MAX if matrix[i][j] is 0 because we are interested in width for matrix[i][j] = 1 only
    vector<vector<int>> left(n, vector<int> (m, INT_MAX));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 1) {
                int lt = j - 1;

                while (lt > -1 && matrix[i][lt] != 0) {
                    lt = left[i][lt];
                }
                left[i][j] = lt;
            }
        }
    }

    // For each matrix[i][j] = 1, if the row below is also 1, increase height of count
    // the width at each stage the min of (j - left[k][j])
    int ans = 0;
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            if (matrix[i][j] == 0) continue;
            int k = i + 1;
            int width = j - left[i][j];
            // ans for first row
            ans = max(ans, width * (k - i));
            while (k < n && matrix[k][j] != 0) {
                // compute answer by considering i .. k rows
                width = min(width, j - left[k][j]);
                ans = max(ans, width * (k - i + 1));
                k++;
            }
        }
    }

    return ans;
}