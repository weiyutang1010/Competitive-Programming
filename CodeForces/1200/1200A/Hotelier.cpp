#include <bits/stdc++.h>
#define ll long long
#define ulli unsigned long long int
#define ld long double  
#define endl "\n"
using namespace std; 


void solve() {
    int n;
    string s;
    cin >> n >> s;

    vector<int> v(10, 0);

    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == 'L') {
            for (int i = 0; i < 10; i++) {
                if (v[i] == 0) {
                    v[i] = 1;
                    break;
                }
            } 
        } else if (s[i] == 'R') {
            for (int i = 9; i >= 0; i--) {
                if (v[i] == 0) {
                    v[i] = 1;
                    break;
                }
            } 
        } else {
            v[s[i] - '0'] = 0;
        }
    }

    for (auto x: v) {
        cout << x;
    }
    cout << endl;
}

int main() 
{ 
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
  
    int t = 1; 
    //cin >> t; 
    while (t--) { 
        solve(); 
    } 
  
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0; 
} 
