#include <bits/stdc++.h>
#include <cmath>

#define ll long long
#define ld long double

using namespace std; 
void solve(); 
int main() 
{ 
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
  
#ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    freopen("error.txt", "w", stderr); 
    freopen("output.txt", "w", stdout); 
#endif 
  
    int t = 1; 
    // cin >> t; 
    while (t--) { 
        solve(); 
    } 
  
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0; 
} 

void solve() 
{ 
	int n, a, b;
    string s;

    cin >> n >> a >> b >> s;

    int passed = 0;
    int count = 0;
    for (int i = 0; i < (int)s.size(); i++) {
        if (s[i] == 'b') {
            count++;
        }

        if (s[i] == 'a' && passed < a + b) {
            cout << "Yes\n";
            passed++;
        } else if (s[i] == 'b' && passed < a + b && count <= b) {
            cout << "Yes\n";
            passed++;
        } else {
            cout << "No\n";
        }
    }
}
