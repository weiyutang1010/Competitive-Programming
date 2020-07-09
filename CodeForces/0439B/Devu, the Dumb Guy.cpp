#include <bits/stdc++.h>
#define ll long long
#define ulli unsigned long long int
#define ld long double  
#define endl "\n"
using namespace std; 


void solve() {
    int n;
    ll x;
    cin >> n >> x;
    vector<int> v(n);

    for (int& num: v) {
        cin >> num;
    }

    sort(v.begin(), v.end());

    ll sum = 0;
    for (int i = 0; i < n; i++) {
        sum += v[i] * x;
        if (x > 1) x--;
    }
    cout << sum << endl;
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
