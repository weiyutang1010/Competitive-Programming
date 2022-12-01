/*
 * author: weiyutang
 */

#include <bits/stdc++.h>
using namespace std;

/* ===== BEGIN USER CODE ===== */

#define ll long long
#define ld long double
#define ii pair<int, int>
#define f first
#define s second
#define endl "\n"

const int MOD = 1e9 + 7;
const vector<ii> dir {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

void compare(int& calories, int& elf_1, int& elf_2, int& elf_3) {
	if (calories >= elf_1) {
		elf_3 = elf_2;
		elf_2 = elf_1;
		elf_1 = calories;
	} else if (calories >= elf_2) {
		elf_3 = elf_2;
		elf_2 = calories;
	} else if (calories >= elf_3) {
		elf_3 = calories;
	}
}

void part2() {
	int calories = 0;
	int elf_1 = 0, elf_2 = 0, elf_3 = 0;
	string st;
	while (getline(cin, st)) {
		if (st.size() == 0) {
			compare(calories, elf_1, elf_2, elf_3);
			calories = 0;
		} else {
			calories += stoi(st);
		}
	}

	compare(calories, elf_1, elf_2, elf_3);
	cout << elf_1 + elf_2 + elf_3 << endl;	
}

void part1() {
	int calories = 0, max_cal = 0;
	string st;
	while (getline(cin, st)) {
		if (st.size() == 0) {
			max_cal = max(max_cal, calories);
			calories = 0;
		} else {
			calories += stoi(st);
		}
	}

	cout << max(max_cal, calories) << endl;
}


int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count());

    int t = 1;
    //cin >> t;
    
    while (t--) {
        // part1();
		part2();
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0;
}
