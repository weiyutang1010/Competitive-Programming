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
	int n, temp;
    vector<int> x;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> temp;
        x.push_back(temp);
    }

    int mean = round(accumulate(x.begin(), x.end(), 0.0) / (float)x.size());
    // int mid = x.size()/2;
    // int num = x[mid];
    int ans = 0;


    for (int i = 0; i < (int)x.size(); i++) {
        ans += pow((x[i] - mean), 2);
    }

    cout << ans << "\n";
}
