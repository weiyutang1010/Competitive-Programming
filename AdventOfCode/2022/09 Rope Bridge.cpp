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

void part2(const vector<pair<char, int>>& motions) {
	int ans = 0;
	unordered_map<char, int> to_dirs {{'R', 0}, {'D', 1}, {'U', 2}, {'L', 3}};

	vector<pair<int, int>> ropes (10, pair<int, int> {0, 0});
	set<pair<int, int>> visited;

	for (const auto& [dir, step]: motions) {
		for (int i = 0; i < step; i++) {
			ropes[0].f += dirs4[to_dirs[dir]][0], ropes[0].s += dirs4[to_dirs[dir]][1];

			for (int j = 1; j < ropes.size(); j++) {
				if (abs(ropes[j-1].f - ropes[j].f) > 0 && abs(ropes[j-1].s - ropes[j].s) > 0 &&
					(abs(ropes[j-1].f - ropes[j].f) > 1 || abs(ropes[j-1].s - ropes[j].s) > 1)) {
					// move diagonally
					ropes[j].f += (ropes[j-1].f - ropes[j].f) / abs(ropes[j-1].f - ropes[j].f);
					ropes[j].s += (ropes[j-1].s - ropes[j].s) / abs(ropes[j-1].s - ropes[j].s);
				} else {
					// move either horizontally or vertically
					if (abs(ropes[j-1].f - ropes[j].f) >= 2) {
						ropes[j].f += (ropes[j-1].f - ropes[j].f) / abs(ropes[j-1].f - ropes[j].f);
					}

					if (abs(ropes[j-1].s - ropes[j].s) >= 2) {
						ropes[j].s += (ropes[j-1].s - ropes[j].s) / abs(ropes[j-1].s - ropes[j].s);
					}
				}
			}
			
			visited.insert({ropes[9].f, ropes[9].s});
		}
	}

	ans = visited.size();

	cout << "Part 2: " << ans << endl;
}

void part1(const vector<pair<char, int>>& motions) {
	int ans = 0;
	unordered_map<char, int> to_dirs {{'R', 0}, {'D', 1}, {'U', 2}, {'L', 3}};

	pair<int, int> head {0, 0}, tail {0, 0};
	set<pair<int, int>> visited;

	for (const auto& [dir, step]: motions) {
		for (int i = 0; i < step; i++) {
			head.f += dirs4[to_dirs[dir]][0], head.s += dirs4[to_dirs[dir]][1];

			if (abs(head.f - tail.f) > 0 && abs(head.s - tail.s) > 0 &&
				(abs(head.f - tail.f) > 1 || abs(head.s - tail.s) > 1)) {
				tail.f += (head.f - tail.f) / abs(head.f - tail.f);
				tail.s += (head.s - tail.s) / abs(head.s - tail.s);
			} else {
				if (abs(head.f - tail.f) >= 2) {
					tail.f += (head.f - tail.f) / abs(head.f - tail.f);
				}

				if (abs(head.s - tail.s) >= 2) {
					tail.s += (head.s - tail.s) / abs(head.s - tail.s);
				}
			}
			
			visited.insert({tail.f, tail.s});
		}
	}

	ans = visited.size();
	cout << "Part 1: " << ans << endl;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count());

    int t = 1;
    //cin >> t;

	char c;
	int n;
	vector<pair<char, int>> motions;
	while (cin >> c >> n) {
		motions.push_back({c, n});
	}

    while (t--) {
        part1(motions);
		part2(motions);
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0;
}
