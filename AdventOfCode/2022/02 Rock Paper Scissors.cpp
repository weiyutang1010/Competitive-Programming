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

void part2() {
	const unordered_map<char, int> score {{'A', 1}, {'B', 2}, {'C', 3}};
	const unordered_map<char, char> win {{'A', 'B'}, {'B', 'C'}, {'C', 'A'}};
	
	int64_t total = 0;
	char a, b;
	while (cin >> a) {
		cin >> b;
		
		char choice;
		if (b == 'X') 
			choice = (((a - 'A' - 1) + 3) % 3) + 'A';
		else if (b == 'Y') 
			choice = a;
		else 
			choice = ((a - 'A' + 1)% 3) + 'A';

		total += score.at(choice);
		if (choice == win.at(a)) 
			total += 6;
		else if (choice == a) 
			total += 3;
	}

	cout << "Part B: " << total << endl;

}

void part1() {
	const unordered_map<char, int> score {{'A', 1}, {'B', 2}, {'C', 3}};
	const unordered_map<char, char> win {{'A', 'B'}, {'B', 'C'}, {'C', 'A'}};
	int64_t total = 0;
	char a, b;
	
	while (cin >> a) {
		cin >> b;
		b -= 'X' - 'A';

		total += score.at(b);
		if (b == win.at(a)) total += 6;
		else if (b == a) total += 3;
	}

	cout << "Part A: " << total << endl;
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
