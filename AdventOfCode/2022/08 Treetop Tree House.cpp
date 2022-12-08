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
const vector<vector<int>> dirs {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

bool in_bound(int r, int c, int n, int m) {
	return r >= 0 && r < n && c >= 0 && c < m;
}

void part2(const vector<vector<int>>& graph) {
	int n = graph.size(), m = graph[0].size();
	int ans = 0;

	for (int row = 1; row < n - 1; row++) {
		for (int col = 1; col < m - 1; col++) {
			int score = 1;
			for (const vector<int>& dir: dirs) {
				int cur_row = row + dir[0], cur_col = col + dir[1], seen = 1;
				while (in_bound(cur_row, cur_col, n, m) && 
						graph[cur_row][cur_col] < graph[row][col]) {
					seen++;
					cur_row += dir[0], cur_col += dir[1];
				}

				if (!in_bound(cur_row, cur_col, n, m)) seen--;
				score *= seen;
			}

			ans = max(ans, score);
		}
	}

	cout << "Part 2: " << ans << endl;
}

void part1(const vector<vector<int>>& graph) {
	int n = graph.size(), m = graph[0].size();
	int64_t ans = 0;

	vector<vector<int>> visible (n, vector<int> (m));

	// up
	for (int col = 0; col < m; col++) {
		int height = -1;
		for (int row = n - 1; row >= 0; row--) {
			if (graph[row][col] > height) {
				visible[row][col] = 1;
				height = graph[row][col];
			}
		}
	}
	
	// down
	for (int col = 0; col < m; col++) {
		int height = -1;
		for (int row = 0; row < n; row++) {
			if (graph[row][col] > height) {
				visible[row][col] = 1;
				height = graph[row][col];
			}
		}
	}

	// left
	for (int row = 0; row < n; row++) {
		int height = -1;
		for (int col = m - 1; col >= 0; col--) {
			if (graph[row][col] > height) {
				visible[row][col] = 1;
				height = graph[row][col];
			}
		}
	}

	// right
	for (int row = 0; row < n; row++) {
		int height = -1;
		for (int col = 0; col < m; col++) {
			if (graph[row][col] > height) {
				visible[row][col] = 1;
				height = graph[row][col];
			}
		}
	}

	// count visible trees
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ans += visible[i][j];
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
	vector<string> input;
	while (getline(cin, st)) {
		input.push_back(st);
	}

	int n = input.size(), m = input[0].size();
	vector<vector<int>> graph (n, vector<int> (m));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			graph[i][j] = input[i][j] - '0';
		}
	}

    while (t--) {
        part1(graph);
		part2(graph);
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0;
}
