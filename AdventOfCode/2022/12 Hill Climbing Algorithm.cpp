/*
 * author: weiyutang
 */

#include <bits/stdc++.h>
using namespace std;

/* ===== BEGIN USER CODE ===== */

#define ll long long
#define ld long double
#define f first
#define s second
#define endl "\n"

const int MOD = 1e9 + 7;
const vector<vector<int>> dirs4 {{0,1}, {1,0}, {-1,0}, {0,-1}};
const vector<vector<int>> dirs8 {{0,1}, {1,0}, {-1,0}, {0,-1}, {-1,-1}, {-1,1}, {1,-1}, {1,1}};

pair<int, int> get_loc(const vector<string>& graph, int start) {
    int n = graph.size(), m = graph[0].size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (start && graph.at(i).at(j) == 'S') {
                return {i, j};
            } else if (!start && graph.at(i).at(j) == 'E') {
                return {i, j};
            }
        }
    }

    return {-1, -1};
}

bool in_bound(const vector<string>& graph, int i, int j, const vector<int>& dir) {
    int n = graph.size(), m = graph[0].size();
    return i + dir[0] >= 0 && i + dir[0] < n && j + dir[1] >= 0 && j + dir[1] < m;
}


bool can_drop(const vector<string>& graph, int i, int j, const vector<int>& dir) {
    char curr_c = (graph[i][j] == 'E' ? 'z' : graph[i][j]);
    char next_c = (graph[i+dir[0]][j+dir[1]] == 'S' ? 'a' : graph[i+dir[0]][j+dir[1]]);
    return (next_c - curr_c) >= -1;
}

void part2(const vector<string>& graph) {
    int n = graph.size(), m = graph[0].size();
	int ans = 0;
    
    vector<vector<int>> visited (n, vector<int> (m, 0));
    queue<vector<int>> bfs; // [row, col, num_step]
    pair<int, int> end = get_loc(graph, 0);
    bfs.push({end.f, end.s, 0});

    // assume no need to climb down
    while (!bfs.empty()) {
        vector<int> curr_loc = bfs.front();
        bfs.pop();

        int i = curr_loc[0], j = curr_loc[1], step = curr_loc[2];
        visited[i][j] = 1;

        if (graph.at(i).at(j) == 'a' || graph.at(i).at(j) == 'S') {
            ans = step;
            break;
        }

        for (const vector<int>& dir: dirs4) {
            if (in_bound(graph, i, j, dir) && !visited[i+dir[0]][j+dir[1]] && can_drop(graph, i, j, dir)) {
                bfs.push({i + dir[0], j + dir[1], step + 1});
                visited[i+dir[0]][j+dir[1]] = 1;
            }
        }
    }

	cout << "Part 2: " << ans << endl;
}

bool can_climb(const vector<string>& graph, int i, int j, const vector<int>& dir) {
    char curr_c = (graph[i][j] == 'S' ? 'a' : graph[i][j]);
    char next_c = (graph[i+dir[0]][j+dir[1]] == 'E' ? 'z' : graph[i+dir[0]][j+dir[1]]);
    return (next_c - curr_c) <= 1;
}

void part1(const vector<string>& graph) {
    int n = graph.size(), m = graph[0].size();
	int ans = 0;
    
    vector<vector<int>> visited (n, vector<int> (m, 0));
    queue<vector<int>> bfs; // [row, col, num_step]
    pair<int, int> start = get_loc(graph, 1);
    bfs.push({start.f, start.s, 0});

    // assume no need to climb down
    while (!bfs.empty()) {
        vector<int> curr_loc = bfs.front();
        bfs.pop();

        int i = curr_loc[0], j = curr_loc[1], step = curr_loc[2];
        visited[i][j] = 1;

        if (graph.at(i).at(j) == 'E') {
            ans = step;
            break;
        }

        for (const vector<int>& dir: dirs4) {
            if (in_bound(graph, i, j, dir) && !visited[i+dir[0]][j+dir[1]] && can_climb(graph, i, j, dir)) {
                bfs.push({i + dir[0], j + dir[1], step + 1});
                visited[i+dir[0]][j+dir[1]] = 1;
            }
        }
    }

    cout << "Part 1: " << ans << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count());

    int t = 1;
    //cin >> t;

	string st;
    vector<string> graph;
    while (getline(cin, st)) {
        graph.push_back(st);
    }


    while (t--) {
        part1(graph);
		part2(graph);
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0;
}
