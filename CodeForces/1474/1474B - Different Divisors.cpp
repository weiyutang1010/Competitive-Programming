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
    int d;
    cin >> d;
    vector<int> primes;
    
    for (int i = d+1; ; i++) {
        int t = 1;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                t = 0;
                break;
            }
        }

        if (t) {
            primes.push_back(i);
            break;
        }
    }

    for (int i = primes[0] + d; ;i++) {
        int t = 1;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                t = 0;
                break;
            }
        }

        if (t) {
            primes.push_back(i);
            break;
        }
    }

    cout << min(1LL * primes[0] * primes[1], 1LL * primes[0] * primes[0] * primes[0]) << endl;

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
