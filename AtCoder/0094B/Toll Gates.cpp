#include <bits/stdc++.h>
#define ll long long
#define ulli unsigned long long int
#define ld long double  
#define endl "\n"
using namespace std; 

void solve() {
    int n, m, x;
    cin >> n >> m >> x;
    
    int temp = 0;
    int left = 0, right = 0;
    for (int i = 0; i < m; i++) {
        cin >> temp;
        if (temp < x) {
            left++;
        } else {
            right++;
        }
    }

    cout << min(left, right) << endl;
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
