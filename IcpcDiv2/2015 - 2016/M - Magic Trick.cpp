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
    vector<int> num(n);
    vector<int> opr(n);
    map<char, int> translate {{'A',1},{'S',2},{'M',3},{'D',4}};
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        cin >> num[i];

        opr[i] = translate[s[0]];
    }

    int ans = 0;
    for (int i = 1; i <= 100; i++) {
        int val = i;
        for (int j = 0; j < n; j++) {
            if (opr[j] == 1) val += num[j];
            else if (opr[j] == 2) {
                val -= num[j];
                if (val < 0) {
                    ans++;
                    break;
                }
            }
            else if (opr[j] == 3) {
                val *= num[j];
            }
            else if (opr[j] == 4) {
                if (val % num[j] != 0) {
                    ans++;
                    break;
                }
                val /= num[j];
            }
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

    while (t--) {
        //cout << "Case #" << i << ": ";
        solve();
    }
 
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0; 
} 
