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
    vector<int> ans;
    int curr, temp;
    cin >> curr;
    temp = curr;
    int cnt = 0;
    for (int i = 0; i < n - 1; i++) {
        cin >> curr;
        if (curr <= temp) {
            cnt++;
            ans.push_back(temp);
        }
        temp = curr;
    }

    ans.push_back(curr);
    cnt++;

    cout << cnt << endl;
    for (int& x: ans) {
        cout << x << " ";
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
