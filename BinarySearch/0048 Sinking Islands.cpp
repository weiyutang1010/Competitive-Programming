#define f first
#define s second

const vector<pair<int, int>> dirs = {{0,1},{1,0},{-1,0},{0,-1}};

void dfs(vector<vector<int>>& board, vector<vector<int>>& visited, int i, int j, int n, int m) {
    // Check is out of bound or 0
    if (i < 0 || j < 0 || i >= n || j >= m || board[i][j] == 0 || visited[i][j]) {
        return;
    }
    
    // set current cell to visited
    visited[i][j] = true;
    board[i][j] = 2;

    // Call dfs on each direction
    for (auto& x: dirs) {
        dfs(board, visited, i + x.f, j + x.s, n, m);
    }

    return;
}

vector<vector<int>> solve(vector<vector<int>>& board) {
    int n = board.size(), m = board[0].size();
    vector<vector<int>> visited (n, vector<int> (m, 0));

    // For each position at the edge
    // Left and right edge
    for (int i = 0; i < n; i++) {
        if (!visited[i][0] && board[i][0] == 1) {
            dfs(board, visited, i, 0, n, m);
        }

        if (!visited[i][m-1] && board[i][m-1] == 1) {
            dfs(board, visited, i, m-1, n, m);
        }
    }

    // Top and bottom edge
    for (int j = 0; j < m; j++) {
        if (!visited[0][j] && board[0][j] == 1) {
            dfs(board, visited, 0, j, n, m);
        }

        if (!visited[n-1][j] && board[n-1][j] == 1) {
            dfs(board, visited, n-1, j, n, m);
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (board[i][j] == 2) {
                board[i][j] = 1;
            } else if (board[i][j] == 1) {
                board[i][j] = 0;
            }
        }
    }
     
    return board;
}