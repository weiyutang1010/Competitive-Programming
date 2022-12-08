/*
 * author: weiyutang1010
 *         Wei Yu Tang
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

void parse_input(const string& st, pair<int, int>& elf_1, pair<int, int>& elf_2) {
    stringstream ss(st);

    string value;
    getline(ss, value, '-');
    elf_1.f = stoi(value);
    getline(ss, value, ',');
    elf_1.s = stoi(value);
    getline(ss, value, '-');
    elf_2.f = stoi(value);
    getline(ss, value, '\n');
    elf_2.s = stoi(value);
}

void part2(const vector<string>& v) {
    int ans = 0;

    for (const string& st: v) {
        pair<int, int> elf_1, elf_2;
        parse_input(st, elf_1, elf_2);
    
        if (elf_1.f <= elf_2.s && elf_1.s >= elf_2.f) {
            ans++;
        } else if (elf_2.f <= elf_1.s && elf_2.s >= elf_1.f) {
            ans++;    
        }
    }

    cout << "Part 2: " << ans << endl;
}

void part1(const vector<string>& v) {
    int ans = 0;

    for (const string& st: v) {
        pair<int, int> elf_1, elf_2;
        parse_input(st, elf_1, elf_2);
    
        if (elf_1.f <= elf_2.f && elf_1.s >= elf_2.s)
            ans++;
        else if (elf_2.f <= elf_1.f && elf_2.s >= elf_1.s) {
            ans++;
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
    while (cin >> st) {
        input.push_back(st);
    }
   
    while (t--) {
        part1(input);
        part2(input);
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0;
}
