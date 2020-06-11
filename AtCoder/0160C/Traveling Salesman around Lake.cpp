#include <bits/stdc++.h>
#define ll long long
#define ulli unsigned long long int
#define ld long double  
using namespace std; 

void solve() {
    int k, n;
    cin >> k >> n;

    int f = 0;
    int temp1;
    int temp2;
    vector<int> d;
    for (int i = 0; i < n; i++) {
        cin >> temp1;
        if (i == 0) {
            f = temp1;
        }

        if (i > 0) {
            int dist = temp1 - temp2;
            d.push_back(dist);
        }
        if (i == n - 1) {
            d.push_back(k - temp1 + f);
        }
        temp2 = temp1;
    }

    sort(d.begin(), d.end());

    int sum = 0;
    for (int i = 0; i < n - 1; i++) {
        sum += d[i];
    }

    cout << sum << "\n";
    
}

int main() 
{ 
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL); 
  
    int t = 1; 
    //cin >> t; 
    while (t--) { 
        solve(); 
    } 
  
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl; 
    return 0; 
} 
