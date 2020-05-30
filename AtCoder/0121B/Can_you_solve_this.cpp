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
	int n, m, c;
    cin >> n >> m >> c;

    int temp;
    vector<int> b;
    for (int i = 0; i < m; i++) {
        cin >> temp;
        b.push_back(temp);
    }

    int count = 0;
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> temp;
            sum += b[j] * temp;
        }


        if (sum + c > 0) {
            count++;
        }
        sum = 0;
    }

    cout << count << "\n";
}
