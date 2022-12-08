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

int get_prio(const char c) {
	if (c >= 'A' && c <= 'Z') {
		return c - 'A' + 27;
	}
	return c - 'a' + 1;
}

void part2(const vector<string>& v) {
	int n = v.size();
	int ans = 0;

	for (int i = 0; i < n; i += 3) {
		vector<int> freq(53);

		for (int j = 0; j < 3; j++) {
			vector<int> seen(53);
			for (const char c: v.at(i+j)) {
				int p = get_prio(c);
				if (!seen[p]) {
					seen[p] = 1;
					freq[p]++;
				}
			}
		}

		for (int p = 1; p <= 52; p++) {
			if (freq[p] == 3) ans += p;
		}
	}

	cout << "Part 2: " << ans << endl;
}

void part1(const vector<string>& v) {
	int64_t ans = 0;

	for (const string& st: v) {
		int n = st.size();
		unordered_map<char, bool> seen;
		
		for (int i = 0; i < n / 2; i++) {
			seen[st.at(i)] = 1;
		}

		for (int i = n / 2; i < n; i++) {
			if (seen[st.at(i)]) {
				ans += get_prio(st.at(i));
				break;
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
	vector<string> input;
	while (getline(cin, st)) {
		input.push_back(st);
	}

    while (t--) {
        part1(input);
		part2(input);
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0;
}
