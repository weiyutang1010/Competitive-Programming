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
    string st1, st2;
    cin >> st1 >> st2;

    for (int i = 0; i < (int)st1.size(); i++) {
        if (st1[i] >= 'A' && st1[i] <= 'Z') {
            st1[i] += 'a' - 'A';
        }
        
        if (st2[i] >= 'A' && st2[i] <= 'Z') {
            st2[i] += 'a' - 'A';
        }

        if (st1[i] < st2[i]) {
            cout << -1 << endl;
            return;
        } else if (st1[i] > st2[i]) {
            cout << 1 << endl;
            return;
        }
    }
    cout << 0 << endl;
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
