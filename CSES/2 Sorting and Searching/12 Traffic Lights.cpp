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
    int x, n;
    cin >> x >> n;
    map<int, int, comp> m;
    map<int, int, comp> max_n;
    m[0] = x;
    max_n[x]++;
 
    int temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        
        // find lower bound of temp
        auto it = m.lower_bound(temp);
    
        // split up range
        int init_range = it->s;
        it->s = temp - it->f;
        m[temp] = init_range - it->s;
 
        max_n[init_range]--;
        if (max_n[init_range] == 0) {
            max_n.erase(init_range);
        }
        max_n[m[temp]]++;
        max_n[it->s]++;
 
        auto it_max = max_n.begin();
        cout << it_max->f << " ";
 
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