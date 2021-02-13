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

    vector<int> v1, v2;

    ll sum = (n * (n + 1)) / 2;
    if (sum & 1) {
        cout << "NO" << endl;
    }

    ll sum1 = 0, sum2 = 0;
    for (int i = n; i > 0; i--) {
        if (sum1 < sum2) {
            v1.push_back(i);
            sum1 += i;
        } else {
            v2.push_back(i);
            sum2 += i;
        }
    }

    cout << "YES" << endl;
    cout << v1.size() << endl;
    for (int i = 0; i < (int)v1.size(); i++) {
        cout << v1[i] << " ";
    }
    cout << endl;
    
    cout << v2.size() << endl;
    for (int i = 0; i < (int)v2.size(); i++) {
        cout << v2[i] << " ";
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
