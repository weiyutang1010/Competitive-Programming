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

    int right_min = INT_MAX;
    int left_max = 0;

    int left, right;
    for (int i = 0; i < n; i++) {
        cin >> left;
        cin >> right;
        left_max = max(left_max, left);
        right_min = min(right_min, right);
    }

    if (n <= 1) {
        cout << 0 << endl;
        return;
    }

    if (left_max - right_min < 1) {
        cout << 0 << endl;
    } else {
        cout << left_max - right_min << endl;
    }

    return;
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
