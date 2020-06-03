#include <bits/stdc++.h>
 
#define ulli unsigned long long
#define ll long long  
#define ld long double
 
using namespace std; 
void solve(); 
int main() 
{ 
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
  
#ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("error.txt", "w", stderr); 
    freopen("output.txt", "w", stdout); 
#endif 
  
    int t = 1; 
    cin >> t; 
    while (t--) { 
        solve(); 
    } 
  
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0; 
} 
void solve() 
{ 
	int x, n;
    // vector<int> v;
    cin >> n >> x;
 
    int odd_count = 0;
    int even_count = 0;
 
    int temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        (temp & 1) ? odd_count++ : even_count++;
    }
 
    if (even_count == 0) {
        if (x & 1) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
        return;
    } else if (odd_count == 0) {
        cout << "No\n";
        return;
    }
 
    if (x == n) {
        if (odd_count & 1) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
        return;
    }
 
    if (x < n) {
        cout << "Yes\n";
    }
}