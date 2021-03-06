#include <bits/stdc++.h>
#define ll long long
#define ulli unsigned long long int
#define ld long double  
#define endl "\n"
using namespace std; 
 
void solve() {
    int n;
    cin >> n;
 
    unordered_map<int, int> m;
    int temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        m[temp] = i+1;
    }
 
    for (int i = 0; i < n; i++) {
        cout << m[i+1] << " ";
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