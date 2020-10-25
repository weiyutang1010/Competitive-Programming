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
    cin >> a >> b;

    if (a == 2 && b == 3) {
        cout << "YES" << endl;
        return;
    }

    vector<int> primes{2};
    for (int i = 3; i < b + 1; i += 2) {
        bool is_prime = true;
        for (int j = 0; j < (int)primes.size(); j++) {
            if (i % primes[j] == 0) {
                is_prime = false;
            }
        }

        if (is_prime) {
            primes.push_back(i);
        }
    }

    if (primes[(int)primes.size() - 2] == a && primes[(int)primes.size() - 1] == b) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
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
