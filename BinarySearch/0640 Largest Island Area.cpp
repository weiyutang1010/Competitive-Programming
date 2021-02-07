#define f first
#define s second

vector<pair<int, int>> dir {{0,1}, {1,0}, {-1,0}, {0,-1}};
int max_n;

int dfs(vector<vector<int>>& matrix, vector<vector<int>>& visited, int i, int j, int& n, int& m) {
    if (visited[i][j]) return 0;
    visited[i][j] = 1;

    if (!matrix[i][j]) return 0;

    int val = 1;
    for (pair<int, int>& x: dir) {
        if (i + x.f >= 0 && i + x.f < n && j + x.s >= 0 && j + x.s < m) {
            if (matrix[i + x.f][j + x.s] == 1) {
                val += dfs(matrix, visited, i + x.f, j + x.s, n, m);
            }
        }
    } 

    return val;
}

int solve(vector<vector<int>>& matrix) {
    int n = matrix.size(), m = matrix[0].size();
    max_n = 0;
    vector<vector<int>> visited (n, vector<int> (m, 0));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j]) {
                max_n = max(max_n, dfs(matrix, visited, i, j, n, m));
            }
        }
    }
    return max_n;
}