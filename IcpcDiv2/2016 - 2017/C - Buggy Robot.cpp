/*
* author: weiyutang
*         Wei Yu Tang 
*/
 
#include <bits/stdc++.h>
 
#define ll long long
#define ld long double
#define ii pair<int, int>
#define f first
#define s second
#define endl "\n"

using namespace std; 
 
const int MOD = 1e9 + 7;

void solve() {
    // Create dirs vector, translate map
    vector<ii> dirs {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    unordered_map<char, ii> translate {{'U', {-1,0}}, {'D',{1,0}}, {'L',{0,-1}}, {'R',{0,1}}};

    // Create vector for robot and exit positions
    ii robot, end;

    // Get board and store position of robot and exit
    int n, m;
    cin >> n >> m;
    vector<vector<char>> board(n, vector<char> (m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> board[i][j];
            if (board[i][j] == 'R') robot = {i, j};
            if (board[i][j] == 'E') end = {i, j};
        }
    }

    // Get command
    string command;
    cin >> command;
    int len = command.size();

    // Create lambda func that returns true if pos is valid and not #
    function<bool(int, int)> valid = [&] (int i, int j) -> bool {
        return (i >= 0 && i < n && j >= 0 && j < m && board[i][j] != '#');
    };

    // Create 3D vector {row, col, command index}
    vector<vector<vector<bool>>> visited(n, vector<vector<bool>> (m, vector<bool> (len+1, false)));

    // Create queue for bfs {row, col, command index, used seconds}
    queue<array<int, 4>> q;

    // Push starting position of robot
    q.push({robot.f, robot.s, 0, 0});

    // BFS
    while (!q.empty()) {
        // Get front and pop
        array<int, 4> curr = q.front();
        q.pop();

        // If not valid or visited then continue
        if (!valid(curr[0], curr[1])) continue;
        if (visited[curr[0]][curr[1]][curr[2]]) continue;

        // Set visited to true
        visited[curr[0]][curr[1]][curr[2]] = true;

        // Create vector of curr position
        array<int, 2> pos {curr[0], curr[1]};

        // If we hit the exit, cout then return
        if (pos[0] == end.f && pos[1] == end.s) {
            cout << curr[3] << endl;
            return;
        }

        // Add a letter to the string before iterating further
        for (auto& x: dirs) {
            if (valid(pos[0] + x.f, pos[1] + x.s)) {
                q.push({pos[0]+x.f, pos[1]+x.s, curr[2], curr[3]+1});
            }
        }

        // Simulate the rest of the command string
        for (int i = curr[2]; i < len; i++) {
            // Move in the direction specified by command
            ii c_dir = translate[command[i]];
            pos[0] += c_dir.f, pos[1] += c_dir.s;

            // If not a valid spot, revert back to prev position
            if (!valid(pos[0], pos[1])) {
                pos[0] -= c_dir.f, pos[1] -= c_dir.s;
            }

            // Check if we are at the exit
            if (pos[0] == end.f && pos[1] == end.s) {
                cout << curr[3] << endl;
                return;
            }

            // If visited, continue else set curr index to visited
            if (visited[pos[0]][pos[1]][i+1]) continue;
            visited[pos[0]][pos[1]][i+1] = true;

            // Insert another letter before continuing to the next command, add to queue
            for (auto& x: dirs) {
                if (valid(pos[0] + x.f, pos[1] + x.s)) {
                    q.push({pos[0]+x.f, pos[1]+x.s, i+1, curr[3]+1});
                }
            }
        }
    }
    
    // Did not find an answer
    cout << "Answer not found" << endl;
    return;
}
 
int main() 
{ 
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
  
    int t = 1;
    //cin >> t;

    while (t--) {
        //cout << "Case #" << i << ": ";
        solve();
    }
 
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0; 
} 
