/*
* author: weiyutang
*         Wei Yu Tang 
*/

#include <bits/stdc++.h>
#define ll long long
#define ulli unsigned long long int
#define ld long double
#define ii pair<int, int>
#define f first
#define s second
#define endl "\n"
using namespace std; 

void solve() {
    int n;
    cin >> n;

    vector<int> v(n);
    for (int &x: v) {
        cin >> x;
    }

    for (int i = 1; i <= n; i++) {
        int count = 0;
        for (int j = 0; j < n; j++) {
            if (v[j] >= i) {
                count++;
            }
        }

        if (count < i) {
            cout << i - 1 << endl;
            return;
        }
    }
    cout << n << endl;
}

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
