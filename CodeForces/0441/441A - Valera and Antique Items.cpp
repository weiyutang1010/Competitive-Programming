#include <bits/stdc++.h>
#define ll long long
#define ulli unsigned long long int
#define ld long double  
#define endl "\n"
using namespace std; 


void solve() {
    int n, v;
    cin >> n >> v;

    int num_s = 0;
    vector<int> sellers;
    for (int i = 0; i < n; i++) {
        int num;
        cin >> num;
        bool can_bargain = false;
        for (int j = 0; j < num; j++) {
            int temp;
            cin >> temp;
            if (temp < v) {
                can_bargain = true;
            }
        }

        if (can_bargain) {
            num_s++;
            sellers.push_back(i + 1);
        }
    }

    sort(sellers.begin(), sellers.end());

    cout << num_s << endl;
    for (auto x: sellers) {
        cout << x << " ";
    }
    cout << endl;
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
