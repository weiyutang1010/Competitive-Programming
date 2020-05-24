#include <bits/stdc++.h> 
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
    /*is Single Test case?*/ cin >> t; 
    while (t--) { 
        solve(); 
    } 
  
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0; 
} 
void solve() 
{
    pair<int,int> rec1;
    pair<int,int> rec2;
    
    cin >> rec1.first;
    cin >> rec1.second;
    cin >> rec2.first;
    cin >> rec2.second;
    
    if (rec1.first == rec2.first && rec1.second + rec2.second == rec1.first) {
        cout << "Yes\n";
    } else if (rec1.first == rec2.second && rec1.second + rec2.first == rec1.first) {
        cout << "Yes\n";
    } else if (rec1.second == rec2.first && rec1.first + rec2.second == rec1.second) {
        cout << "Yes\n";
    } else if (rec1.second == rec2.second && rec1.first + rec2.first == rec1.second) {
        cout << "Yes\n";
    } else {
        cout << "No\n";
        return;
    }
} 