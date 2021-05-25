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
    int64_t a, b;
    cin >> a >> b;
    
    int64_t ans = 0;

    // For every factor under sqrt(b)
    for (int64_t factor = 1; factor * factor <= b; factor++) {
        // Equation: 
        // factor * x = num1, factor * (x + 1) = num2, factor * (x + 2)...

        // Find min_x and max_x such that factor * min_x is in [a, b]
        int64_t min_x = max(factor, (a + factor - 1) / factor);
        int64_t max_x = b / factor;
        
        // Handle square number case (don't count twice)
        if (factor * factor >= a && factor * factor <= b) {
            ans += factor;
            min_x++;
        }

        // calculate number of numX
        int64_t num_x = max_x - min_x + 1;

        // use equation and add everything to ans
        ans += num_x * min_x;
        ans += num_x * factor;
        ans += (num_x * (num_x - 1)) / 2;
    }
        
    cout << ans << endl;
}
 
int main() 
{ 
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
  
    int t = 1;
    // cin >> t;

    while (t--) {
        //cout << "Case #" << i << ": ";
        solve();
    }
 
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0; 
} 
