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
 
const int MOD = 1e9 + 7;

void solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    unordered_map<int, int> cnt;
    ii max_n = {0, 0};

    // Count num for each c and keep track of largest count
    for (int& x: v) {
        cin >> x;
        cnt[x % 3]++;
        if (cnt[x % 3] > max_n.s) max_n = {x % 3, cnt[x % 3]};
    }

    int x = max_n.f;
    int each = n / 3;
    int ans = 0;
  

    // Handle cases when two same largest count
    if (cnt[0] == cnt[1] && cnt[0] == max_n.s) x = 0;
    else if (cnt[0] == cnt[2] && cnt[0] == max_n.s) x = 2;
    else if (cnt[1] == cnt[2] && cnt[1] == max_n.s) x = 1;

    // Distribute number from largest to the right
    for (int i = 0; i < 100; i++) {
        if (cnt[x] > each) {
            ans += cnt[x] - each;
            cnt[(x + 1) % 3] += cnt[x] - each;
            cnt[x] = each;
        }
        x = (x + 1) % 3;
    }

    cout << ans << endl;
}
 
int main() 
{ 
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
  
    int t = 1;
    cin >> t;

    while (t--) {
        //cout << "Case #" << i << ": ";
        solve();
    }
 
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0; 
} 
