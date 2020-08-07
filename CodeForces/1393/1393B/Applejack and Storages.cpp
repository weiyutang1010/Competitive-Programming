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
    int n, q;
    cin >> n;
    map<int,int> m;
    for (int i = 0; i < n; i++) {
        int temp;
        cin >> temp;
        m[temp]++;
    }

    int num_pairs = 0;
    int more_than_4 = 0;
    for (auto x: m) {
        num_pairs += x.s/2;
        if (x.s >= 4) {
            more_than_4++;
        }
    }

    cin >> q;

    for (int i = 0; i < q; i++) {
        char sign;
        int len;
        cin >> sign >> len;

        if (sign == '+') {
            m[len]++;
            if (!(m[len] & 1)) {
                num_pairs++;
            }

            if (m[len] == 4) {
                more_than_4++;
            }
        } else {
            m[len]--;
            if (m[len] & 1) {
                num_pairs--;
            }

            if (m[len] == 3) {
                more_than_4--;
            }
        }

        if (num_pairs >= 4 && more_than_4 > 0) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
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
