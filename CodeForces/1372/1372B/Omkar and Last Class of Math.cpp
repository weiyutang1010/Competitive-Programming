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
    int ans = 0;
    
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) {
            ans = i;
            break;
        }
    }

    if (ans == 0) {
        cout << 1 << " " << n - 1 << endl;
        return;
    }
   
    cout << (n / ans) << " " << (n - (n / ans)) << endl;
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
