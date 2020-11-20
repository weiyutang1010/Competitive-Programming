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
 
struct comp {
    bool operator()(const int& a, const int& b) {
        return a > b;
    }
};
 
void solve() {
    int a, b;
    cin >> a >> b;
    vector<int> customers(b);
    map<int, int, comp> prices;
 
    for (int i = 0; i < a; i++) {
        int temp;
        cin >> temp;
        prices[temp]++;
    }
 
    for (int i = 0; i < b; i++) {
        cin >> customers[i];
    }
 
    for (int i = 0; i < b; i++) {
        auto w = prices.lower_bound(customers[i]);
        if (w == prices.end()) {
            cout << -1 << endl;
        } else {
            cout << w->first << endl;
            w->second--;
            if (w->second == 0) {
                prices.erase(w);
            }
        }
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