/*
* author: weiyutang
*         Wei Yu Tang 
*/
 
#include <bits/stdc++.h>
 
#define ll long long
#define ld long double
#define ii pair<int, int>
#define f first
#define s second
#define endl "\n"
 
using namespace std; 

void solve() {
    int n;
    cin >> n;
    
    ii score {0, 0};
    
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        if (a > b) {
            score.f++;
        } else if (a < b) {
            score.s++;
        }
    }
    
    if (score.f > score.s) {
        cout << "Mishka" << endl;
    } else if (score.f < score.s) {
        cout << "Chris" << endl;
    } else {
        cout << "Friendship is magic!^^" << endl;
    }
    
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