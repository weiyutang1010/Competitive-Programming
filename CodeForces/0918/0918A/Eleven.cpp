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

    vector<int> fib{1, 1};
    while (fib[fib.size() - 1] < n) {
        fib.push_back(fib[fib.size() - 1] + fib[fib.size() - 2]);
    }

    int pt = 1;
    for (int i = 0; i < n; i++) {
        if (i+1 == fib[pt]) {
            cout << 'O';
            pt++;
            continue;
        } 
        cout << 'o';
    }
    cout << endl;

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
