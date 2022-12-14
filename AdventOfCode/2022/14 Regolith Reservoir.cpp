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

void part2(vector<vector<int>> graph, int floor) {
	int ans = 0;
    
    // fill sand until the source is blocked
    while (true) {
        int x = 500;

        for (int y = 0; y < floor; y++) {
            if (graph[x][y+1] && graph[x-1][y+1] && graph[x+1][y+1]) {
                graph[x][y] = 1;
                break;
            } else if (graph[x][y+1] && graph[x-1][y+1]) {
                x += 1;
            } else if (graph[x][y+1]) {
                x -= 1;
            }
        }

        ans++;
        if (graph[500][0] == 1)
            break;
    }

	cout << "Part 2: " << ans << endl;
}

void part1(vector<vector<int>> graph, int floor) {
    int ans = 0;

    // fill sand until one unit reach the floor level
    while (true) {
        bool rest = false;
        int x = 500;

        for (int y = 0; y < floor - 1; y++) {
            if (graph[x][y+1] && graph[x-1][y+1] && graph[x+1][y+1]) {
                rest = true;
                graph[x][y] = 1;
                break;
            } else if (graph[x][y+1] && graph[x-1][y+1]) {
                x += 1;
            } else if (graph[x][y+1]) {
                x -= 1;
            }
        }

        if (!rest) break;
        ans++;
    }

    cout << "Part 1: " << ans << endl;
}

int parse_input(const vector<string>& paths, vector<vector<int>>& graph) {
    int n = paths.size();
    vector<vector<pair<int, int>>> v (n);

    // convert paths to a 2d list of [x, y]
    int floor = 0;
    int idx = 0;
    for (const string& st: paths) {
        string token;
        stringstream ss(st);
        while (getline(ss, token, ' ')) {
            if (token == "->")
                continue;

            stringstream ss2(token);
            getline(ss2, token, ',');
            int x = stoi(token);
            getline(ss2, token, ',');
            int y = stoi(token);

            v[idx].push_back({x, y});
            floor = max(floor, y);
        }
        idx++;
    }

    floor += 2;

    // fill the graph with block
    for (vector<pair<int, int>> path: v) {
        int m = path.size();

        for (int i = 1; i < m; i++) {
            int x, y;
            if (path[i].f == path[i-1].f) {
                x = path[i].f;
                for (int y = min(path[i].s, path[i-1].s); y <= max(path[i].s, path[i-1].s); y++) {
                    graph[x][y] = 1;
                }
            } else {
                y = path[i].s;
                for (int x = min(path[i].f, path[i-1].f); x <= max(path[i].f, path[i-1].f); x++) {
                    graph[x][y] = 1;
                }
            }
        }
    }

    // fill the floor level of the graph
    for (int x = 0; x < 1000; x++) {
        graph[x][floor] = 1;
    }

    return floor;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count());

    int t = 1;
    //cin >> t;

    string st;
    vector<string> inputs;
    while (getline(cin, st)) {
        inputs.push_back(st);
    }

    // graph[i][j] = 1 if blocked at i,j, 0 if empty
    vector<vector<int>> graph(1000, vector<int> (300));
    int floor = parse_input(inputs, graph);

    while (t--) {
        part1(graph, floor);
		part2(graph, floor);
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0;
}
