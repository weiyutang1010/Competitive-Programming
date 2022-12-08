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

void init_cargo(const vector<string>& v, vector<stack<char>>& cargo) {
    vector<stack<char>> temp_cargo;
    
    for (const string& st: v) {
        int c_idx = 1, cargo_idx = 0;

        while (c_idx < st.size()) {
            char c = st.at(c_idx);
            if (c != ' ') {
                while (cargo_idx >= temp_cargo.size()) {
                    temp_cargo.push_back(stack<char> ());
                }
                temp_cargo[cargo_idx].push(c);
            }
            cargo_idx++;
            c_idx += 4;
        }
    }

    for (stack<char>& temp: temp_cargo) {
        cargo.push_back(stack<char> ());

        while (!temp.empty()) {
            cargo.back().push(temp.top());
            temp.pop();
        }
    }
}

void parse_inst(const string& inst, int& start, int& end, int& freq) {
    string temp;
    stringstream ss(inst);

    ss >> temp >> freq;
    ss >> temp >> start;
    ss >> temp >> end;
}

void part2(vector<stack<char>> cargo, const vector<string>& instructions) {
    for (const string& inst: instructions) {
        int start, end, freq;
        parse_inst(inst, start, end, freq);

        // use a temporary stack to keep the order same
        stack<char> temp;
        for (int i = 0; i < freq; i++) {
            temp.push(cargo[start-1].top());
            cargo[start-1].pop();
        }

        for (int i = 0; i < freq; i++) {
            cargo[end-1].push(temp.top());
            temp.pop();
        }
    }

    cout << "Part 2: ";
    for (const stack<char>& stk: cargo) {
        cout << stk.top();
    }
    cout << endl;

}

void part1(vector<stack<char>> cargo, const vector<string>& instructions) {
    for (const string& inst: instructions) {
        int start, end, freq;
        parse_inst(inst, start, end, freq);

        for (int i = 0; i < freq; i++) {
            cargo[end-1].push(cargo[start-1].top());
            cargo[start-1].pop();
        }
    }

    cout << "Part 1: ";
    for (const stack<char>& stk: cargo) {
        cout << stk.top();
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count());

    int t = 1;
    //cin >> t;
    
    string st;
    vector<string> input;
    vector<stack<char>> cargo;
    while (getline(cin, st)) {
        if (st.size() == 0) break;
        input.push_back(st);
    }
    init_cargo(input, cargo);

    vector<string> instructions;
    while (getline(cin, st)) {
        instructions.push_back(st);
    }
   
    while (t--) {
        part1(cargo, instructions);
        part2(cargo, instructions);
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0;
}
