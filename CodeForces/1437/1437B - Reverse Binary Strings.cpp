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
    string s;
    cin >> n >> s;
    string s1 = '1' + s + '0';
    string s2 = '0' + s + '1';


    int ans1 = 0, ans2 = 0;
    for (int i = 1; i < n + 2; i++) {
        if (s1[i] == s1[i - 1]) {
            ans1++;
        }

        if (s2[i] == s2[i - 1]) {
            ans2++;
        }
    }

    cout << min(ans1 / 2, ans2 / 2) << endl;
} 

int main() 
{ 
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
  
    int t = 1; 
    cin >> t;
 
    for (int i = 1; i <= t; i++) {
        //cout << "Case #" << i << ": ";
        solve();
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0; 
} 
