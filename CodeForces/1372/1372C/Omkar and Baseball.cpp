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
    int temp = 0;
    int in_order = 0;
    ii range {-1, -1};
    for (int i = 0; i < n; i++) {
        cin >> temp;
        v[i] = temp;

        if (temp != i+1) {
            if (range.f == -1) {
                range.f = i;
            }
            range.s = max(range.s, i);
        }
    }
    
    if (range.f == -1) {
        cout << 0 << endl;
        return;
    }

    for (int i = range.f; i < range.s; i++) {
        if (v[i] == i + 1) {
            in_order++;
        }
    }

    if (in_order >= 1){
        cout << 2 << endl;
    } else {
        cout << 1 << endl;
    }

        
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
