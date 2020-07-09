#include <bits/stdc++.h>
#define ll long long
#define ulli unsigned long long int
#define ld long double  
#define endl "\n"
using namespace std; 


void solve() {
    int n, k1, k2;
    cin >> n >> k1 >> k2;

    bool p1_win = true;
    int max_num = 0;
    for (int i = 0; i < k1; i++) {
        int temp = 0;
        cin >> temp;
        max_num = max(max_num, temp);
    }

    for (int i = 0; i < k2; i++) {
        int temp;
        cin >> temp;
        if (temp > max_num) {
            p1_win = false;
        }
    } 
    cout << ((p1_win) ? "YES" : "NO") << endl;
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
