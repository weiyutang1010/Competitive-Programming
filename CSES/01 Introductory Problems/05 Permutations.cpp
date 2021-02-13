/*
* author: weiyutang
*         Wei Yu Tang 
*/

#include <bits/stdc++.h>

#define ll long long
#define ulli unsigned long long int
#define ld long double
#define ii pair<int, int>
#define f first
#define s second
#define endl "\n"

using namespace std; 

void solve() {
    int n;
    cin >> n;

    if (n == 1) {
        cout << 1 << endl;
        return;
    } else if (n == 2 || n == 3) {
        cout << "NO SOLUTION" << endl;
        return;
    }

    for (int i = n - ((n & 1) ? 1 : 2); i > 0; i -= 2) {
        cout << i << " ";
    }
    cout << n << " ";
    for (int i = 1; i < n; i += 2) {
        cout << i << " ";
    }
    cout << endl;
}

int main() 
{ 
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
  
    int t = 1; 
    //cin >> t;
 
    for (int i = 1; i <= t; i++) {
        //cout << "Case #" << i << ": ";
        solve();
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0; 
} 
