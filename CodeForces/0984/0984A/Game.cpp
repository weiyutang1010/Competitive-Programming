#include <bits/stdc++.h>
#define ll long long
#define ulli unsigned long long int
#define ld long double  
#define endl "\n"
using namespace std; 


void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (int &x: v) {
        cin >> x;
    }

    sort(v.begin(), v.end());
    n--;
    cout << v[n / 2] << endl;
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
