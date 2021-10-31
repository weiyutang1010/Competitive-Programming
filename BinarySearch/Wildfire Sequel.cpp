#define f first
#define s second
#define ii pair<int, int>

int n, m;
const vector<ii> dir = {{0,1}, {1,0}, {-1,0}, {0,-1}};

bool in_bound(int i, int j, int x, int y) {
    return i + x >= 0 && i + x < n && j + y >= 0 && j + y < m;
}

bool at_exit(int i, int j, int x, int y) {
    return ((i+x == 0 && j+y == 0) || (i+x == n-1) && (j+y == m-1));
}

bool solve(vector<vector<int>>& matrix) {
    n = matrix.size(), m = matrix[0].size();
    bool exit1 = false, exit2 = false;

    // push pos of person and fire into queue
    queue<ii> person;
    queue<ii> fire;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (matrix[i][j] == 1) person.push({i, j});
            else if (matrix[i][j] == 2) {
                fire.push({i, j});
            }
        }
    }

    // if person is already at the exit
    if (at_exit(person.front().f, person.front().s, 0, 0)) return true;

    // if the exit is already blocked
    if (matrix[0][0] == 2 || matrix[0][0] == 3) exit1 = true;
    if (matrix[n-1][m-1] == 2 || matrix[n-1][m-1] == 3) exit2 = true;

    // Apply bfs to person then fire. Check who gets to exit first
    while (true) {
        // Person's turn
        int ps = person.size();
        bool has_move = false;
        for (int a = 0; a < ps; a++) {
            int i = person.front().f, j = person.front().s;
            person.pop();
            
            for (auto& [x,y]: dir) {
                // if space is valid, push the new location
                if (in_bound(i, j, x, y) && matrix[i+x][j+y] == 0) {
                    if (at_exit(i, j, x, y)) {
                        return true;
                    }
                    person.push({i+x, j+y});
                    matrix[i+x][j+y] = 1;
                    has_move = true;
                }
            }
        }
        // if all person has no valid move
        if (!has_move) return false;

        // Fire's turn
        int fs = fire.size();
        for (int b = 0; b < fs; b++) {
            int i = fire.front().f, j = fire.front().s;
            fire.pop();
            for (auto& [x,y]: dir) {
                if (in_bound(i, j, x, y) && matrix[i+x][j+y] <= 1) {
                    // if fire covers exit
                    if (i+x == 0 && j+y == 0) exit1 = true;
                    if (i+x == n-1 && j+y == m-1) exit2 = true;
                    fire.push({i+x, j+y});
                    matrix[i+x][j+y] = 2;
                }
            }
        }
        
        if (exit1 && exit2) return false;
    }
}
