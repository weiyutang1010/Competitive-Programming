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

void inc_cycle2(int& cycle, int X) {
	if (cycle == X || cycle == X + 1 || cycle == X + 2) {
		cout << '#';
	} else {
		cout << '.';
	}

	if (cycle % 40 == 0) {
		cycle -= 40;
		cout << endl;
	}
	cycle++;
}

void part2(const vector<pair<string, int>>& inputs) {
	// int ans = 0;
	int X = 1;
	int cycle = 1;

	for (const auto& [inst, value]: inputs) {
		if (inst == "noop") {
			inc_cycle2(cycle, X);
		} else {
			inc_cycle2(cycle, X);
			inc_cycle2(cycle, X);
			X += value;
		}
	}
	
	// cout << "Part 2: " << ans << endl;
}

void inc_cycle(int& cycle, int X, int& ans) {
	if (cycle >= 20 && (cycle - 20) % 40 == 0) {
		ans += X * cycle;
	}
	cycle++;
}

void part1(const vector<pair<string, int>>& inputs) {
	int ans = 0;
	int X = 1;
	int cycle = 1;

	for (const auto& [inst, value]: inputs) {
		if (inst == "noop") {
			inc_cycle(cycle, X, ans);
		} else {
			inc_cycle(cycle, X, ans);
			inc_cycle(cycle, X, ans);
			X += value;
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
	vector<pair<string, int>> inputs;
	while (getline(cin, st)) {
		stringstream ss(st);
		
		string token;
		ss >> token;

		if (token == "addx") {
			ss >> token;
			inputs.push_back({"addx", stoi(token)});
		} else {
			inputs.push_back({"noop", 0});
		}
	}

    while (t--) {
        part1(inputs);
		part2(inputs);
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0;
}
