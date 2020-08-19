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
    int a, b;
    cin >> a;
    vector<int> v1(a);
    for (int i = 0; i < a; i++) {
        cin >> v1[i];
    }
    cin >> b;
    vector<int> v2(b);
    for (int i = 0; i < b; i++) {
        cin >> v2[i];
    }

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());


    int ans = 0;
    for (int i = 0, j = 0; i < a && j < b;) {
        if (abs(v1[i] - v2[j]) < 2) {
            ans++;
            i++; j++;
        } else if (v1[i] < v2[j]) {
            i++;
        } else {
            j++;
        }
    }
    cout << ans << endl;
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
