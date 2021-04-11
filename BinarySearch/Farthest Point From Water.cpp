int solve(vector<vector<int>>& matrix) {
    vector<array<int,2>> dir = {{0, 1},{1, 0},{-1, 0},{0, -1}};
    int n = matrix.size(), m = matrix[0].size();

    bool has_one = 0, has_zero = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 0) {
                has_zero = 1;
            } else {
                has_one = 1;
            }
        }
    }

    if (!has_zero || !has_one) return -1;

    auto valid = [&] (int x, int y) -> bool {
        return x >= 0 && x < n && y >= 0 && y < m;
    };

    // Do a BFS from each point on land and get the distance to closest water
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 1) {
                queue<array<int, 2>> bfs;
                vector<vector<int>> visited (n, vector<int> (m, 0));
                bfs.push({i, j});

                while (!bfs.empty()) {
                    array<int, 2> curr = bfs.front();
                    bfs.pop();
                    int row = curr[0], col = curr[1];

                    if (matrix[row][col] == 0) {
                        ans = max(ans, abs(row - i) + abs(col - j));
                        break;
                    }

                    for (auto& [x, y]: dir) {
                        if (valid(row + x, col + y) && !visited[row+x][col+y]) {
                            bfs.push({row + x, col + y});
                        }
                    }
                }
            }
        }
    }


    return ans;
}  