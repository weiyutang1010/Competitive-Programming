#include <bits/stdc++.h>
#define ll long long
#define ulli unsigned long long int
#define ld long double  
using namespace std; 
void solve(); 
int main() 
{ 
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
  
    int t = 1; 
    cin >> t; 
    while (t--) { 
        solve(); 
    } 
  
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0; 
} 

// Discard number greater than 2048. If we have at least 1 2048, print yes.
// Check if the rest of the number add up to 2048. 
// If we only have 1 of every number less than 2048, they add up to 2047. 
// So if they add up to 2048, there must be at least 2 of a number.
void solve() {
    int n;
    cin >> n;
    unordered_map<int, int> m;
    ll temp;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        if (temp > 2048) {
            continue;
        } else {
            m[temp]++;
        }
    }

    if (m[2048] > 0) {
        cout << "YES\n";
        return;
    }

    int sum = 0;
    int num = 1024;
    while(num > 0) {
        sum += num * (m[num]);
        num /= 2;
    }

    if (sum >= 2048) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
    }
}
