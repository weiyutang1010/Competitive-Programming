#include <bits/stdc++.h>
#define ll long long
#define ulli unsigned long long int
#define ld long double  
#define endl "\n"
using namespace std; 

void solve() {
    string b;
    cin >> b;

    int num_ones = 0;
    int num_zeros = 0;
    for (auto x: b) {
        (x == '1') ? num_ones++ : num_zeros++;
    }

    int ans = INT_MAX;
    int done_ones = 0;
    int done_zeros = 0;
    for (int i = 0; i < (int)b.size(); i++) {
        (b[i] == '1') ? done_ones++ : done_zeros++;
        ans = min (ans, min(done_zeros + num_ones - done_ones, done_ones + num_zeros - done_zeros));
    }

    cout << ans << endl;
}

int main() 
{ 
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
  
    int t = 1; 
    cin >> t; 
    while (t--) { 
        solve(); 
    } 
  
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0; 
} 
