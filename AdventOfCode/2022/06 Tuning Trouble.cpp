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


void part2(const vector<string>& v) {
    int ans = 0;

    for (const string& st: v) {
        int n = st.size();
        vector<int> seen(26, -1);
        seen[st.at(0) - 'a']++;

        int lt, rt;
        for (lt = 0, rt = 1; rt < n; rt++) {
            int c = st.at(rt) - 'a';
            
            if (seen[c] != -1) {
                while (lt <= seen[c]) {
                    seen[st.at(lt) - 'a'] = -1;
                    lt++;
                }
            }
            
            seen[c] = rt;
            if (rt - lt + 1 == 14) {
                ans = rt + 1;
                break;
            }
        }
        
        cout << "Part 2: " << ans << endl;
    }

}

void part1(const vector<string>& v) {
    int ans = 0;

    for (const string& st: v) {
        int n = st.size();
        vector<int> seen(26, -1);
        seen[st.at(0) - 'a']++;

        int lt, rt;
        for (lt = 0, rt = 1; rt < n; rt++) {
            int c = st.at(rt) - 'a';
            
            if (seen[c] != -1) {
                while (lt <= seen[c]) {
                    seen[st.at(lt) - 'a'] = -1;
                    lt++;
                }
            }
            
            seen[c] = rt;
            if (rt - lt + 1 == 4) {
                ans = rt + 1;
                break;
            }
        }
        
        cout << "Part 1: " << ans << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    srand(chrono::steady_clock::now().time_since_epoch().count());

    int t = 1;
    //cin >> t;
     
    vector<string> input;
    string st;
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
