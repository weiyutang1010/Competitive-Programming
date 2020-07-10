#include <bits/stdc++.h>
#define ll long long
#define ulli unsigned long long int
#define ld long double  
#define endl "\n"
using namespace std; 
 
 
void solve() {
    ll n;
    cin >> n;
 
    int count = 0;
    int row = 1;
    while (true) {
        if (n == 1) {
            cout << count << endl;
            return;
        }
 
        if (n % 6 == 0) {
            n /= 6;
            row = 0;
        } else if (row == 3) {
            cout << -1 << endl;
            return;
        } else {
            n *= 2;
            row++;
        }
        count++;
    }
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