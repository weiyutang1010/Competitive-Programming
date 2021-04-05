#define f first
#define s second

const vector<pair<int, int>> dir {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

void dfs(vector<vector<int>>& matrix, vector<vector<int>>& visited, int i, int j, int n, int m) {
    visited[i][j] = 1;
    for (auto& [x, y]: dir) {
        if (i + x >= 0 && i + x < n && j + y >= 0 && j + y < m) {
            if (matrix[i+x][j+y] == 1 && !visited[i+x][j+y]) {
                dfs(matrix, visited, i + x, j + y, n, m);
            }
        }
    }
    return;
}

int solve(vector<vector<int>>& matrix) {
    int n = matrix.size();
    int m = matrix[0].size();
    
    int ans = 0;
    vector<vector<int>> visited(n, vector<int> (m, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 1 && !visited[i][j]) {
                dfs(matrix, visited, i, j, n, m);
                ans++;
            }
        }
    }

    return ans;
}