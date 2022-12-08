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

vector<int> dir_size;

struct Dir {
	unordered_map<string, Dir*> dirs;
	vector<pair<string, int>> files;
};

void part2() {
	const int64_t total_disk = 70000000;
	const int64_t unused_disk = 30000000;
	int64_t del_size = unused_disk - (total_disk - dir_size.back());

	for (const int& size: dir_size) {
		if (size >= del_size) {
			cout << "Part 2: " << size << endl;
			return;
		}
	}
}

void part1() {
	int64_t ans = 0;

	for (const int& size: dir_size) {
		if (size <= 100000) ans += size;
	}

	cout << "Part 1: " << ans << endl;
}

int64_t get_dirsize(const Dir* curdir) {
	int64_t total_size = 0;

	for (auto& [name, size]: curdir->files) {
		total_size += size;
	}

	for (auto& [name, dir]: curdir->dirs) {
		total_size += get_dirsize(dir);
	}

	dir_size.push_back(total_size);
	return total_size;
}

int parse_input(const vector<string>& commands, Dir* curdir, int idx) {
	int n = commands.size();
	string token;

	for (int i = idx; i < n; i++) {
		stringstream ss(commands.at(i));
		ss >> token;

		if (token[0] == '$') {
			ss >> token;
			if (token == "cd") {
				ss >> token;
				if (token == "..") {
					return i;
				}

				if (curdir->dirs.find(token) != curdir->dirs.end()) {
					i = parse_input(commands, curdir->dirs[token], i + 1);
				}
			}
		} else if (token[0] == 'd') {
			ss >> token;
			curdir->dirs[token] = new Dir;
		} else {
			int size = stoi(token);
			ss >> token;
			curdir->files.push_back({token, size});
		}
	}

	return n;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count());

    int t = 1;
    //cin >> t;

	string st;
	vector<string> commands;
	while (getline(cin, st)) {
		commands.push_back(st);
	}

	Dir* home = new Dir;
	parse_input(commands, home, 0);
	
	get_dirsize(home);
	sort(dir_size.begin(), dir_size.end());

    while (t--) {
        part1();
		part2();
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0;
}
